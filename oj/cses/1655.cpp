/******************************************************************************
Link: https://cses.fi/problemset/task/1655
Code: 1655
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-22-17.39.21
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct BitTrie{
    const int MAXLG = 30;
    struct Node{
        int nxt[2];

        Node(){
            memset(nxt, -1, sizeof nxt);
        }
    };

    vector<Node> T;
    BitTrie(){
        T.emplace_back();
    }

    void add(int x){
        int p = 0;
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;

            if(T[p].nxt[bit] == -1){
                T[p].nxt[bit] = T.size();
                T.emplace_back();
            }

            p = T[p].nxt[bit];
        }
    }

    int find_max_xor(int x){
        int p = 0;
        int res = 0;
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;
            if(T[p].nxt[bit ^ 1] != -1) bit ^= 1;

            res |= bit << b;

            p = T[p].nxt[bit];
            if(p == -1) break;
        }

        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    BitTrie trie;
    int prexor = 0;

    int ans = 0;
    trie.add(0);
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;

        prexor ^= cur;

        ans = max(ans, prexor ^ trie.find_max_xor(prexor));
        trie.add(prexor);
    }

    cout << ans << '\n';

    return 0;
}
