/******************************************************************************
Link: https://judge.yosupo.jp/problem/set_xor_min
Code: set_xor_min
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-10-15.50.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct BitTrie{
    const static int MAXLG = 30;
    struct Node{
        int nxt[2];
        int stop;
        int passed;

        Node(): stop(0), passed(0){
            memset(nxt, -1, sizeof nxt);
        }
    };

    vector<Node> T;

    BitTrie(){
        T.emplace_back();
    }

    bool existed(int x){
        int p = 0;
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;

            if(T[p].nxt[bit] == -1)
                return false;

            p = T[p].nxt[bit];
        }

        return T[p].stop > 0;
    }

    void insert(int x){
        if(existed(x)) return;

        int p = 0;
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;

            if(T[p].nxt[bit] == -1){
                T[p].nxt[bit] = T.size();
                T.emplace_back();
            }

            T[p].passed++;
            p = T[p].nxt[bit];
        }

        T[p].passed++;
        T[p].stop++;
    }

    void erase(int x){
        if(!existed(x)) return;

        int p = 0;
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;

            T[p].passed--;
            p = T[p].nxt[bit];
        }

        T[p].passed--;
        T[p].stop--;
    }

    int minXor(int s){
        int p = 0;
        int res = 0;
        for(int b = MAXLG; b >= 0; --b){
            int bit = s >> b & 1;

            int nxt = T[p].nxt[bit];
            if(nxt != -1 && T[nxt].passed > 0) p = nxt;
            else if(T[p].nxt[bit ^ 1] != -1){
                p = T[p].nxt[bit ^ 1];
                res |= 1 << b;
            }
        }

        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int Q;
    cin >> Q;

    BitTrie trie;
    while(Q--){
        int type, x;
        cin >> type >> x;

        if(type == 0) trie.insert(x);
        else if(type == 1) trie.erase(x);
        else if(type == 2) cout << trie.minXor(x) << "\n";
    }

    return 0;
}
