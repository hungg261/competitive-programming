/******************************************************************************
Link: https://codeforces.com/problemset/problem/888/G
Code: 888G
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-25-23.38.57
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;
    vector<vector<int>> cmpID;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
        cmpID.resize(n + 1);
    }

    vector<int>& getComp(int u){
        return cmpID[find(u)];
    }

    void init(){
        for(int u = 0; u <= n; ++u)
            create(u);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
    }

    int find(int v){
        return par[v] == v ? v : par[v] = find(par[v]);
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];

            for(int ele: cmpID[b])
                cmpID[a].push_back(ele);
            cmpID[b].clear();

            return true;
        }

        return false;
    }
};

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
        T.reserve(6200000);
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
        }

        return T[p].id;
    }
};

const int MAXN = 2e5;
int arr[MAXN + 5], n;

pair<int, int> best[MAXN + 5];
void Boruvka(){
    int components = n;

    DSU dsu(n);
    dsu.init();

    BitTrie trie;
    for(int i = 1; i <= n; ++i){
        trie.add(arr[i], i);
        dsu.getComp(i).push_back(i);
    }

    long long mst = 0;
    while(components > 1){
        for(int c = 1; c <= n; ++c){
            if(dsu.find(c) != c) continue;

            const vector<int>& cmpID = dsu.getComp(c);
            for(int id: cmpID) trie.pop(arr[id]);

            int minXor = -1;
            best[c] = {-1, -1};
            for(int u: cmpID){
                int v = trie.minXor(arr[u]);
                if(v == -1) continue;

                if(minXor == -1 || (arr[u] ^ arr[v]) < minXor){
                    minXor = (arr[u] ^ arr[v]);
                    best[c] = {u, v};
                }
            }

            for(int id: cmpID) trie.add(arr[id], id);
        }

        for(int c = 1; c <= n; ++c){
            if(dsu.find(c) != c || best[c].first == -1) continue;

            int u, v; tie(u, v) = best[c];

            if(dsu.same(u, v)) continue;

            dsu.unite(u, v);
            mst += (arr[u] ^ arr[v]);

            --components;
        }
    }

    cout << mst << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    Boruvka();

    return 0;
}
