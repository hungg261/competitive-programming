/******************************************************************************
Link: https://cses.fi/problemset/task/2104
Code: 2104
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-05-13.56.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

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

    int q;
    cin >> q;

    auto lower_bound = [&](const string &pattern, function<bool(const string&, const string&)> f){
        int lo = 0, hi = (int)sa.size();
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            if(f(S.substr(sa[mid], pattern.size()), pattern))
                hi = mid;
            else lo = mid + 1;
        }
        return lo;
    };

    int n = sa.size();
    int lg = __lg(n) + 1;
    vector<vector<int>> table(n, vector<int>(lg + 1));
    for(int i = 0; i < n; ++i)
        table[i][0] = sa[i];

    for(int j = 1; j <= lg; ++j){
        for(int i = 0; i + (1 << j) - 1 < n; ++i){
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }

    while(q--){
        string p;
        cin >> p;

        int l = lower_bound(p, [](const string &a, const string &b){ return a >= b; });
        int r = lower_bound(p, [](const string &a, const string &b){ return a > b; }) - 1;

        if(l > r) cout << "-1\n";
        else{
            int bit = __lg(r - l + 1);
            int pos = min(table[l][bit], table[r - (1 << bit) + 1][bit]);

            cout << pos + 1 << "\n";
        }
    }

    return 0;
}
