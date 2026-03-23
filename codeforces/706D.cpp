/******************************************************************************
Link: https://codeforces.com/problemset/problem/706/D
Code: 706D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-22-11.11.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct BitTrie{
    static const int LENGTH = 30;
    struct Node{
        int nxt[2];
        int cnt;
        int passed = 0;

        Node(): cnt(0), passed(0){
            memset(nxt, -1, sizeof nxt);
        }
    };

    vector<Node> T;

    BitTrie(){
        T.emplace_back();
    }

    void add(int x){
        int p = 0;
        for(int b = LENGTH; b >= 0; --b){
            int cur = x >> b & 1;

            if(T[p].nxt[cur] == -1){
                T[p].nxt[cur] = T.size();
                T.emplace_back();
            }

            p = T[p].nxt[cur];
            ++T[p].passed;
        }

        ++T[p].cnt;
    }

    void pop(int x){
        int p = 0;
        for(int b = LENGTH; b >= 0; --b){
            int cur = x >> b & 1;

            if(T[p].nxt[cur] == -1){
                return;
            }

            p = T[p].nxt[cur];
            --T[p].passed;
        }

        --T[p].cnt;
    }

    int maxXor(int x){
        int p = 0;
        int res = 0;
        for(int b = LENGTH; b >= 0; --b){
            int bit = x >> b & 1;
            if(T[p].nxt[bit ^ 1] != -1 && T[T[p].nxt[bit ^ 1]].passed > 0) bit ^= 1;

            p = T[p].nxt[bit];
            res |= bit << b;
        }

        return res ^ x;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    BitTrie trie;

    int t;
    cin >> t;

    trie.add(0);
    while(t--){
        char type; int x;
        cin >> type >> x;

        if(type == '+') trie.add(x);
        else if(type == '-') trie.pop(x);
        else{
            cout << trie.maxXor(x) << '\n';
        }
    }

    return 0;
}
