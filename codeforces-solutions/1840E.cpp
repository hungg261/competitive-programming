/******************************************************************************
Link: https://codeforces.com/problemset/problem/1840/E
Code: 1840E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-31-11.17.15
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void add(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    void update(int idx, int val){
        add(idx, val - get(idx, idx));
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

void solve(){
    string s[2];
    cin >> s[0] >> s[1];

    int t, q, n = s[0].size();
    cin >> t >> q;

    s[0] = "#" + s[0];
    s[1] = "#" + s[1];

    FenwickTree fwt(n);
    for(int i = 1; i <= n; ++i)
        fwt.update(i, s[0][i] != s[1][i]);

    queue<pair<int, int>> que;
    for(int T = 1; T <= q; ++T){
        int type;
        cin >> type;

        if(T == que.front().first){
            int pos = que.front().second;
            que.pop();

            fwt.update(pos, s[0][pos] != s[1][pos]);
        }

        if(type == 1){
            int pos;
            cin >> pos;

            fwt.update(pos, 0);
            que.push({T + t, pos});
        }
        else if(type == 2){
            int id1, pos1, id2, pos2;
            cin >> id1 >> pos1 >> id2 >> pos2;

            --id1; --id2;
            swap(s[id1][pos1], s[id2][pos2]);

            fwt.update(pos1, s[0][pos1] != s[1][pos1]);
            fwt.update(pos2, s[0][pos2] != s[1][pos2]);
        }
        else{
            cout << (fwt.get(n) == 0 ? "YES" : "NO") << '\n';
        }
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
