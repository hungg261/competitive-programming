/******************************************************************************
Link: https://codeforces.com/problemset/problem/979/D
Code: 979D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-22-12.03.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct BitTrie{
    static const int MAXLG = 30;
    struct Node{
        int nxt[2];
        int cnt;
        int smallest;

        Node(): cnt(0), smallest(INT_MAX){
            memset(nxt, -1, sizeof nxt);
        }
    };

    vector<Node> T;

    BitTrie(){ T.emplace_back(); }

    void add(int x){
        int p = 0;
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;

            if(T[p].nxt[bit] == -1){
                T[p].nxt[bit] = T.size();
                T.emplace_back();
            }

            p = T[p].nxt[bit];
            T[p].smallest = min(T[p].smallest, x);
        }

        ++T[p].cnt;
    }

    int solve(int x, int s){
        int p = 0;
        int res = 0;
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;
            if(T[p].nxt[bit ^ 1] != -1 && T[T[p].nxt[bit ^ 1]].smallest <= s - x) bit ^= 1;
            if(T[p].nxt[bit] == -1 || T[T[p].nxt[bit]].smallest > s - x) return -1;

            p = T[p].nxt[bit];
            res |= bit << b;
        }

        return res;
    }
};

const int MAXVAL = 1e5;
vector<int> d[MAXVAL + 5];
BitTrie trie[MAXVAL + 5];
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 1; i <= MAXVAL; ++i){
        for(int j = i; j <= MAXVAL; j += i){
            d[j].push_back(i);
        }
    }

    int q;
    cin >> q;

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int u;
            cin >> u;

            for(int ds: d[u]) trie[ds].add(u);
        }
        else{
            int x, k, s;
            cin >> x >> k >> s;

            int res = x % k == 0 ? trie[k].solve(x, s) : -1;
            cout << res << '\n';
        }
    }

    return 0;
}
