/******************************************************************************
Link: https://cses.fi/problemset/task/2105
Code: 2105
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-04-19.12.04
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int ALPHABET = 256;

vector<int> suffix_array(string S){
    S += '$';
    int n = S.size();

    const int SIZE = max(n, ALPHABET);

    vector<int> p(n), c(n);

    {
        vector<int> cnt(SIZE, 0);
        for(int i = 0; i < n; ++i){
            cnt[S[i]]++;
        }

        for(int i = 1; i < SIZE; ++i)
            cnt[i] += cnt[i - 1];

        for(int i = n - 1; i >= 0; --i){
            p[--cnt[S[i]]] = i;
        }

        int classes = c[p[0]] = 0;
        for(int i = 1; i < n; ++i){
            if(S[p[i]] != S[p[i - 1]]) ++classes;
            c[p[i]] = classes;
        }
    }

    int loops = __lg(n * 2 - 1) + 1;
    for(int k = 1; k < loops; ++k){
        int half = 1 << (k - 1);

        vector<int> cnt(SIZE, 0);
        vector<int> new_p(n);
        for(int i = 0; i < n; ++i){
            new_p[i] = ((p[i] - half) % n + n) % n;
            cnt[c[new_p[i]]]++;
        }

        for(int i = 1; i < SIZE; ++i)
            cnt[i] += cnt[i - 1];

        for(int i = n - 1; i >= 0; --i){
            p[--cnt[c[new_p[i]]]] = new_p[i];
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

vector<int> build_lcp(const string &S, const vector<int> &p){
    int n = p.size();
    vector<int> ranked(n), lcp(n - 1);
    for(int i = 0; i < n; ++i)
        ranked[p[i]] = i;

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

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string S;
    cin >> S;

    vector<int> sa = suffix_array(S);
    vector<int> lcp = build_lcp(S, sa);

    int n = S.size(), sz = sa.size();
    int res = 0;
    for(int i = 0; i + 1 < sz; ++i){
        res += (n - sa[i]) - lcp[i];
    }

    res += n - sa[n];

    cout << res << "\n";

    return 0;
}
