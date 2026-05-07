/******************************************************************************
Link: https://codeforces.com/contest/1895/problem/D
Code: 1895D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-07-16.01.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct BitTrie{
    const int MAXLG = 20;
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

        return x ^ res;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> pre(n + 1);
    pre[0] = 0;
    BitTrie trie;
    trie.add(pre[0]);

    for(int i = 1; i < n; ++i){
        int a; cin >> a;

        pre[i] = pre[i - 1] ^ a;
        trie.add(pre[i]);
    }

    vector<int> b(n + 1);
    for(int b1 = 0; b1 < n; ++b1){
        if(trie.find_max_xor(b1) < n){
            b[1] = b1;
            for(int i = 1; i < n; ++i){
                b[i + 1] = pre[i] ^ b[1];
            }
            break;
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << b[i] << " ";
    }
    cout << "\n";

    return 0;
}
