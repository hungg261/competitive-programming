#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5, MAXM = 2e5;
int n, m;

struct Edge{
    int a, b, c;

    bool operator < (const Edge& other){ return c < other.c; }
} edges[MAXM + 5];

struct DSU{
    vector<int> lab;

    DSU(int n){ lab.resize(n + 1); }

    void create(int v){
        lab[v] = -1;
    }

    int find_set(int v){
        return lab[v] < 0 ? v : lab[v] = find_set(lab[v]);
    }

    void union_sets(int a, int b){
        a = find_set(a); b = find_set(b);
        if(a != b){
            if(lab[a] < lab[b]) swap(a, b);
            lab[a] += lab[b];
            lab[b] = a;
        }
    }
};

void kruskal(){
    sort(edges + 1, edges + m + 1);
    DSU dsu(n); for(int i = 1; i <= n; ++i) dsu.create(i);

    int ans = 0, edges_cnt = 0;
    for(int i = 1; i <= m; ++i){
        if(dsu.find_set(edges[i].a) != dsu.find_set(edges[i].b)){
            dsu.union_sets(edges[i].a, edges[i].b);
            ans += edges[i].c;
            ++edges_cnt;
        }
    }

    if(edges_cnt != n - 1) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        edges[i] = {a, b, c};
    }

    kruskal();

    return 0;
}
