/******************************************************************************
Link: https://codeforces.com/problemset/problem/842/D
Code: 842D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-22-15.03.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct BitTrie{
    static const int MAXLG = 30;
    int swapped[MAXLG + 1];

    struct Node{
        int nxt[2];
        int cnt;
        int passed;

        Node(): cnt(0), passed(0){
            memset(nxt, -1, sizeof nxt);
        }
    };

    vector<Node> T;
    BitTrie(){
        T.emplace_back();
        memset(swapped, 0, sizeof swapped);
    }

    void add(int x){
        int p = 0;
        ++T[p].passed;

        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;

            if(T[p].nxt[bit] == -1){
                T[p].nxt[bit] = T.size();
                T.emplace_back();
            }

            p = T[p].nxt[bit];
            ++T[p].passed;
        }

        ++T[p].cnt;
    }

    void xorAll(int x){
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;
            if(bit){
                swapped[b] ^= 1;
            }
        }
    }

    int find_mex(){
        int p = 0;
        int mex = 0;
        for(int b = MAXLG; b >= 0; --b){
            int need = 1 << b;
            int bit = swapped[b];

            if(T[p].nxt[bit] == -1 || T[T[p].nxt[bit]].passed < need){
                p = T[p].nxt[bit];
            }
            else{
                mex |= 1 << b;
                p = T[p].nxt[bit ^ 1];
            }

            if(p == -1) break;
        }

        return mex;

    }

    void printAll(int p, int cur, int b = MAXLG){
        if(b == -1){
            cerr << cur << '\n';
            return;
        }

        for(int c = 0; c < 2; ++c){
            if(T[p].nxt[c] != -1){
                printAll(T[p].nxt[c], cur << 1 | (c ^ swapped[b]), b - 1);
            }
        }
    }

    void dfs(int p){
        for(int c = 0; c < 2; ++c){
            if(T[p].nxt[c] != -1){
                cerr << p << ' ' << T[p].nxt[c] << ' ' << c << '\n';
                dfs(T[p].nxt[c]);
            }
        }
    }
};


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;

    BitTrie trie;
    set<int> values;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        if(values.count(cur)) continue;

        values.insert(cur);
        trie.add(cur);
    }

    while(q--){
        int x; cin >> x;

        trie.xorAll(x);
        cout << trie.find_mex() << '\n';
    }

    return 0;
}
