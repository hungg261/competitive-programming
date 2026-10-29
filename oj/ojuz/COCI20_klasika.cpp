/******************************************************************************
Link: https://oj.uz/problem/view/COCI20_klasika
Code: COCI20_klasika
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-29-20.46.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Trie{
    const int MAXLG = 31;
    struct Node{
        int nxt[2];
        set<int> S;

        bool contains(int l, int r){
            auto it = S.lower_bound(l);
            if(it != S.end() && *it <= r) return true;
            return false;
        }

        Node(){
            memset(nxt, -1, sizeof nxt);
            S.clear();
        }
    };

    vector<Node> T;
    Trie(){
        T.emplace_back();
    }

    void insert(int x, int in){
        int p = 0;
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;

            if(T[p].nxt[bit] == -1){
                T[p].nxt[bit] = T.size();
                T.emplace_back();
            }

            p = T[p].nxt[bit];
            T[p].S.insert(in);
        }
    }

    int maxXor(int x, int l, int r){
        int p = 0;
        int res = 0;
        for(int b = MAXLG; b >= 0; --b){
            int bit = x >> b & 1;

            int target = T[p].nxt[bit ^ 1];
            if(target != -1){
                if(T[target].contains(l, r)){
                    p = target;
                    res |= 1 << b;
                    continue;
                }
            }

            p = T[p].nxt[bit];
            if(p == -1) break;
        }
        return res;
    }
};


const int MAXN = 2e5;
vector<int> adj[MAXN + 5];
int N = 1, Q, tin[MAXN + 5], tout[MAXN + 5], Timer = 0;
int pre[MAXN + 5];

struct Query{
    string type;
    int x, y;

    void input(){
        cin >> type >> x >> y;
        if(type == "Add"){
            int v = ++N;
            adj[x].push_back(v);
            adj[v].push_back(x);
            pre[v] = pre[x] ^ y;
        }
    }
}; vector<Query> queries;

void dfs(int u = 1, int prv = -1){
    tin[u] = ++Timer;
    for(int v: adj[u]){
        if(v == prv) continue;
        dfs(v, u);
    }
    tout[u] = Timer;
}

void solve(){
    Trie trie;
    int cur = 1;
    trie.insert(pre[1], tin[1]);
    for(const Query &q: queries){
        if(q.type == "Add"){
            ++cur;
            trie.insert(pre[cur], tin[cur]);
        }
        else{
            cout << trie.maxXor(pre[q.x], tin[q.y], tout[q.y]) << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> Q;

    queries.resize(Q);
    for(int i = 0; i < Q; ++i){
        queries[i].input();

    }

    dfs();
    solve();

    return 0;
}
