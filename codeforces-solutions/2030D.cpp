/******************************************************************************
Link: https://codeforces.com/contest/2030/problem/D
Code: 2030D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-05-17.42.27
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Range{
    int l, r;

    bool operator < (const Range& other) const{
        return l < other.l;
    }
};

void solve(){
    int n, q;
    cin >> n >> q;

    const int MAXLG = __lg(n);
    vector<vector<pair<int, int>>> table(n + 1, vector<pair<int, int>>(MAXLG + 1));
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;
        table[i][0].first = cur;
        table[i][0].second = cur;
    }

    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            table[i][j].first = min(table[i][j - 1].first, table[i + (1 << j - 1)][j - 1].first);
            table[i][j].second = max(table[i][j - 1].second, table[i + (1 << j - 1)][j - 1].second);
        }
    }

    auto get = [&table](int l, int r){
        int bit = __lg(r - l + 1);
        int mn = min(table[l][bit].first, table[r - (1 << bit) + 1][bit].first);
        int mx = max(table[l][bit].second, table[r - (1 << bit) + 1][bit].second);
        return make_pair(mn, mx);
    };

    auto good = [&get](const Range& rg){
        int mn, mx;
        tie(mn, mx) = get(rg.l, rg.r);

        return rg.l <= mn && mx <= rg.r;
    };

    string s;
    cin >> s;

    s = "#" + s;

    vector<Range> ranges;
    ranges.push_back({1, 1});
    for(int i = 2; i <= n; ++i){
        if(s[i - 1] == 'L' && s[i] == 'R'){
            ranges.push_back({i, i});
        }
        Range& cur = ranges.back();
        cur.r = i;
    }

    int ok = 0;
    for(const Range& rg: ranges){
        int mn, mx;
        tie(mn, mx) = get(rg.l, rg.r);

        ok += good(rg);
    }

    set<Range> S(begin(ranges), end(ranges));
    while(q--){
        int idx;
        cin >> idx;

        for(int i = idx; i <= idx + 1; ++i){
            if(s.substr(i - 1, 2) == "LR"){
                auto it = S.lower_bound({i, -1});
                auto prv = prev(it);

                if(good(*it)) --ok;
                if(good(*prv)) --ok;

                int L = prv->l, R = it->r;
                S.erase(it);
                S.erase(prv);

                Range newRg = {L, R};
                S.insert(newRg);

                if(good(newRg)) ++ok;
            }
        }

        s[idx] = (s[idx] == 'L' ? 'R' : 'L');

        for(int i = idx; i <= idx + 1; ++i){
            if(s.substr(i - 1, 2) == "LR"){
                auto it = prev(S.lower_bound({i, -1}));

                if(good(*it)) --ok;
                int L = it->l, R = it->r;

                S.erase(it);

                Range newL = {L, i - 1}, newR = {i, R};
                S.insert(newL);
                S.insert(newR);

                if(good(newL)) ++ok;
                if(good(newR)) ++ok;
            }
        }

        cout << (ok == (int)S.size() ? "YES\n" : "NO\n");
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
