/******************************************************************************
Link: https://oj.vnoi.info/problem/hsg_hcm_v2_25_hsnv
Code: hsg_hcm_v2_25_hsnv
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-16-14.54.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXM = 2e5, MAXQ = 2e5;
const int MAXLG = __lg(MAXN) + 1;
int N, M, Q, a[MAXM + 5];
vector<int> adj[MAXN + 5];
pair<int, int> table[MAXN * 2 + 5][MAXLG + 5];
int tin[MAXN + 5], Timer;
int h[MAXN + 5], lg[MAXN * 2 + 5];
long long hsnv[MAXM * 4 + 5];

void dfs(int u, int prv){
    tin[u] = ++Timer;
    table[Timer][0] = {h[u], u};
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        dfs(v, u);
        table[++Timer][0] = {h[u], u};
    }
}

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) <= Timer; ++i){
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }

    lg[1] = 0;
    for(int i = 2; i <= N * 2; ++i){
        lg[i] = lg[i >> 1] + 1;
    }
}

int find_lca(int u, int v){
    int l = tin[u], r = tin[v];
    if(l > r) swap(l, r);

    int bit = lg[r - l + 1];
    return min(table[l][bit], table[r - (1 << bit) + 1][bit]).second;
}

int find_dist(int u, int v){
    return h[u] + h[v] - 2 * h[find_lca(u, v)];
}

namespace Subtask12{

void solve(){
    while(Q--){
        char type; cin >> type;

        if(type == 'e'){
            int X, V; cin >> X >> V;

            for(int nv = 1; nv <= M; ++nv){
                if(a[nv] == X){
                    hsnv[nv] += V;
                }
            }
        }
        else if(type == 't'){
            int L, R, Z;
            cin >> L >> R >> Z;

            for(int nv = L; nv <= R; ++nv){
                hsnv[nv] -= find_dist(a[nv], Z);
                a[nv] = Z;
            }
        }
        else if(type == 'q'){
            int K;
            cin >> K;

            cout << hsnv[K] << "\n";
        }
    }
}

};

namespace Subtask3{

vector<pair<int, int>> nodes[MAXM * 4 + 5];
vector<pair<int, int>> history[MAXN + 5];
int inc[MAXN + 5];

void push(int id){
    for(const pair<int, int>& Data: nodes[id]){
        int time, pos; tie(time, pos) = Data;
        const vector<pair<int, int>>& his = history[pos];

        int latest = upper_bound(begin(his), end(his), make_pair(time, -1)) - begin(his) - 1;
        for(int& it = inc[pos]; it <= latest; ++it){
            hsnv[id] += his[it].second;
        }

        hsnv[id << 1] += hsnv[id];
        nodes[id << 1].push_back(Data);

        hsnv[id << 1 | 1] += hsnv[id];
        nodes[id << 1 | 1].push_back(Data);
    }

    hsnv[id] = 0;
    nodes[id].clear();
}

void add(int id, int l, int r, int u, int v, const pair<int, int>& Data){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        nodes[id].push_back(Data);
        return;
    }

    push(id);

    int mid = (l + r) >> 1;
    add(id << 1, l, mid, u, v, Data);
    add(id << 1 | 1, mid + 1, r, u, v, Data);
}

int query(int id, int l, int r, int idx){
    if(l == r){
        int hs = 0;
        for(const pair<int, int>& Data: nodes[id]){
            hs -= find_dist(a[idx], Data.second);
            a[idx] = Data.second;
        }
        hsnv[id] = 0;

        return hs;
    }

    push(id);

    int mid = (l + r) >> 1;
    if(idx <= mid) return query(id << 1, l, mid, idx);
    else return query(id << 1 | 1, mid + 1, r, idx);
}

void solve(){
    for(int i = 1; i <= M; ++i){
        history[a[i]].emplace_back(0, 0);
    }

    for(int t = 1; t <= Q; ++t){
        char type; cin >> type;

        if(type == 'e'){
            int X, V; cin >> X >> V;

            history[X].emplace_back(t, V);
        }
        else if(type == 't'){
            int L, R, Z;
            cin >> L >> R >> Z;

//            for(int nv = L; nv <= R; ++nv){
//                hsnv[nv] -= find_dist(a[nv], Z);
//                a[nv] = Z;
//            }

            add(1, 1, M, L, R, {t, Z});
        }
        else if(type == 'q'){
            int K;
            cin >> K;

            cout << query(1, 1, M, K) << "\n";
        }
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("HSNV.INP","r",stdin);
//    freopen("HSNV.OUT","w",stdout);

    cin >> N >> M >> Q;
    for(int i = 1; i <= M; ++i){
        cin >> a[i];
    }
    for(int i = 1; i < N; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    compute();

    Subtask3::solve();

    return 0;
}
