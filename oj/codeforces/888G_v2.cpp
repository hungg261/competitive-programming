/******************************************************************************
Link: https://codeforces.com/problemset/problem/888/G
Code: 888G
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-25-23.38.57
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct BitTrie{
    static const int MAXLG = 30;
    struct Node{
        int nxt[2];
        int passed, id;

        Node(): passed(0), id(-1){
            memset(nxt, -1, sizeof nxt);
        }
    };

    vector<Node> T;
    BitTrie(){
        T.reserve(6500000);
        T.emplace_back();
    }

    void clear(){
        T.clear();
        T.emplace_back();
    }

    void add(int x, int id){
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

        T[p].id = id;
    }

    void pop(int x){
        int p = 0;
        --T[p].passed;
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;

            p = T[p].nxt[bit];
            --T[p].passed;
        }

        T[p].id = -1;
    }

    int minXor(int x){
        int p = 0;
        int res = 0;
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;

            if(T[p].nxt[bit] != -1 &&
               T[T[p].nxt[bit]].passed > 0){
                p = T[p].nxt[bit];
            }
            else{
                bit ^= 1;
                if(T[p].nxt[bit] == -1 || T[T[p].nxt[bit]].passed == 0)
                    return -1;

                p = T[p].nxt[bit];
            }

            res |= bit << b;
        }

        return res;
    }
};

const int MAXN = 2e5;
int arr[MAXN + 5], n;
BitTrie trie;

int solve(int b, int l, int r){
    if(b < 0 || l >= r) return 0;

    int mid = l;
    for(; mid <= r && (arr[mid] >> b & 1) == 0; ++mid);
    --mid;

    int cost = solve(b - 1, l, mid) + solve(b - 1, mid + 1, r);
    if(l <= mid && mid < r){ // 2 halves
        int minXor = 1 << 30;

        trie.clear();
        for(int i = l; i <= r; ++i){
            if(i <= mid) trie.add(arr[i], i);
            else{
                minXor = min(minXor, arr[i] ^ trie.minXor(arr[i]));
            }
        }

        cost += minXor;
    }

    return cost;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);

    cout << solve(30, 1, n) << '\n';

    return 0;
}
