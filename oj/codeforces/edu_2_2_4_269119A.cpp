/******************************************************************************
Link: https://codeforces.com/edu/course/2/lesson/2/4/practice/contest/269119/problem/A
Code: edu_2_2_4_269119A
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-04-14.36.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int ALPHABET = 256;

vector<int> build_lcp(const string &S, const vector<int> &p){
    int n = p.size();
    vector<int> ranked(n);
    vector<int> lcp(n - 1);
    for(int i = 0; i < n; ++i){
        ranked[p[i]] = i;
    }

    int k = 0;
    for(int i = 0; i < n; ++i){
        if(ranked[i] == n - 1){
            k = 0;
            continue;
        }

        int j = p[ranked[i] + 1];
        while(i + k < n && j + k < n && S[i + k] == S[j + k])
            ++k;

        lcp[ranked[i]] = k;
        if(k > 0) --k;
    }

    return lcp;
}

vector<int> suffix_array(string S){
    S += '$';
    int n = S.size();

    int lg = __lg(n * 2 - 1) + 1;
    vector<int> p(n), c(n);

    {
        const int SIZE = max(n, ALPHABET);
        vector<int> cnt(SIZE, 0);
        for(int i = 0; i < n; ++i)
            cnt[S[i]]++;

        for(int ch = 1; ch < SIZE; ++ch)
            cnt[ch] += cnt[ch - 1];

        for(int i = n - 1; i >= 0; --i){
            p[--cnt[S[i]]] = i;
        }

        int classes = c[p[0]] = 0;
        for(int i = 1; i < n; ++i){
            if(S[p[i]] != S[p[i - 1]]) ++classes;
            c[p[i]] = classes;
        }
    }

    for(int k = 1; k < lg; ++k){
        int len = 1 << k, half = len >> 1;
        vector<int> pn(n);
        for(int i = 0; i < n; ++i){
            pn[i] = ((p[i] - half) % n + n) % n;
        }

        const int SIZE = max(n, ALPHABET);
        vector<int> cnt(SIZE, 0);
        for(int i = 0; i < n; ++i){
            cnt[c[pn[i]]]++;
        }

        for(int ch = 1; ch < SIZE; ++ch)
            cnt[ch] += cnt[ch - 1];

        for(int i = n - 1; i >= 0; --i){
            p[--cnt[c[pn[i]]]] = pn[i];
        }

        vector<int> new_c(n);
        int classes = new_c[p[0]] = 0;
        for(int i = 1; i < n; ++i){
            pair<int, int> cur = {c[p[i]], c[(p[i] + half) % n]},
                        prv = {c[p[i - 1]], c[(p[i - 1] + half) % n]};
            if(cur != prv) ++classes;
            new_c[p[i]] = classes;
        }

        c = move(new_c);
    }

    return p;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string S;
    cin >> S;

    vector<int> p = suffix_array(S);
    vector<int> lcp = build_lcp(S, p);

    for(int x: p) cout << x << " ";
    cout << "\n";
    for(int x: lcp) cout << x << " ";

    return 0;
}
