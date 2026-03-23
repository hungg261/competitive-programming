/******************************************************************************
Link: https://codeforces.com/group/2W1wfqmLNZ/contest/675179/problem/C
Code: Group_2W1wfqmLNZ_675179C
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-13-14.08.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
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

            return true;
        }

        return false;
    }
};

struct Edge{
    int u, v, w;

    bool operator < (const Edge& other) const{
        return w < other.w;
    }
};

const int dx[2] = {0, 1}, dy[2] = {1, 0};

int A, B, N, M;
vector<int> Xs, Ys;

int e(int i, int j){ return (M + 1) * i + j; } // encode
pair<int, int> decode(int id){ return {id / (M + 1), id % (M + 1)}; }

// vet can
void trau(){
    vector<Edge> edges;
    for(int i = 0; i + 1 < N + 2; ++i){
        int vx = Xs[i + 1] - Xs[i];

        for(int j = 0; j + 1 < M + 2; ++j){
            int vy = Ys[j + 1] - Ys[j];

//            cerr << i << ' ' << j << ' ' << e(i, j) << ": " << vx << ' ' << vy << '\n';

            for(int d = 0; d < 1; ++d){
                int nx = i + dx[d], ny = j + dy[d];
                if(0 <= nx && nx < N + 1 && 0 <= ny && ny < M + 1){
                    edges.push_back({e(i, j), e(nx, ny), vx});
                }
            }
            for(int d = 1; d < 2; ++d){
                int nx = i + dx[d], ny = j + dy[d];
                if(0 <= nx && nx < N + 1 && 0 <= ny && ny < M + 1){
                    edges.push_back({e(i, j), e(nx, ny), vy});
                }
            }
        }
    }

//    for(auto e: edges){
//        int x1, y1, x2, y2;
//        tie(x1, y1) = decode(e.u);
//        tie(x2, y2) = decode(e.v);
//
//        cerr << x1 << ' ' << y1 << " <-> " << x2 << ' ' << y2 << ": " << e.w << '\n';
//    }

    auto kruskal = [&](){
        sort(begin(edges), end(edges));
        long long mst = 0;

        DSU dsu((N + 1) * (M + 1) + 1);
        dsu.init();
        for(const Edge& e: edges){
            if(dsu.unite(e.u, e.v)){
                mst += e.w;
            }
        }

        return mst;
    };

    cout << kruskal() << '\n';
}

void solve(){
    vector<int> a;
    vector<int> b;

    for(int i = 0; i + 1 < N + 2; ++i) a.push_back(Xs[i + 1] - Xs[i]);
    for(int j = 0; j + 1 < M + 2; ++j) b.push_back(Ys[j + 1] - Ys[j]);

    sort(begin(a), end(a));
    sort(begin(b), end(b));
    int n = a.size(), m = b.size();

    int i = 0, j = 0;
    long long res = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            if(j == 0) res += a[i] * (M - j);
            else res += a[i];
            ++i;
        }
        else{
            if(i == 0) res += b[j] * (N - i);
            else res += b[j];
            ++j;
        }

        cerr << i << ' ' << j << ": " << res << '\n';
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("RUTVAN.INP","r",stdin);
//    freopen("RUTVAN.OUT","w",stdout);

    cin >> A >> B >> N >> M;
    Xs.resize(N); Ys.resize(M);

    for(int i = 0; i < N; ++i){
        cin >> Xs[i];
    }
    for(int i = 0; i < M; ++i){
        cin >> Ys[i];
    }

    Xs.push_back(0); Xs.push_back(A);
    Ys.push_back(0); Ys.push_back(B);
    sort(begin(Xs), end(Xs));
    sort(begin(Ys), end(Ys));

//    trau();
    solve();

    return 0;
}
