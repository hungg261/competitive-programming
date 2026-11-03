/******************************************************************************
Link: https://codeforces.com/problemset/problem/990/G
Code: 990G
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-03-14.31.53
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXVAL = 2e5;
int n, a[MAXN + 5];
vector<pair<int, int>> edges;

namespace DSU{

int sz[MAXN + 5], par[MAXN + 5];

int find(int v){ return par[v] == v ? v : par[v] = find(par[v]); }

bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;

    sz[a] += sz[b];
    par[b] = a;
    return true;
}

}


namespace Solve{

//vector<int> nodes_div[MAXVAL + 5];
//vector<pair<int, int>> edges_div[MAXVAL + 5];
vector<int> nodes_pos[MAXVAL + 5];vector<pair<int, int>> edges_pos[MAXVAL + 5];

void compute(){
//    for(int u = 1; u <= n; ++u){
//        for(int d = 1; d * d <= a[u]; ++d){
//            if(a[u] % d == 0){
//                nodes_div[d].push_back(u);
//                if(d * d != a[u]) nodes_div[a[u] / d].push_back(u);
//            }
//        }
//    }

    for(int u = 1; u <= n; ++u){
        nodes_pos[a[u]].push_back(u);
    }
}

void solve(){
    compute();

    vector<long long> cnt(MAXVAL + 1);
    for(int d = 1; d <= MAXVAL; ++d){
        for(int b = d; b <= MAXVAL; b += d){
            for(int u: nodes_pos[b]){
                DSU::par[u] = u;
                DSU::sz[u] = 1;
            }
        }

        for(int b = d; b <= MAXVAL; b += d){
            for(const pair<int, int> &e: edges_pos[b]){
                DSU::unite(e.first, e.second);
            }
        }

        cnt[d] = 0;
        for(int b = d; b <= MAXVAL; b += d){
            for(int u: nodes_pos[b]){
                if(DSU::find(u) == u)
                    cnt[d] += 1LL * DSU::sz[u] * (DSU::sz[u] + 1) / 2;
            }
        }
    }

    for(int d = MAXVAL; d >= 1; --d){
        for(int b = d * 2; b <= MAXVAL; b += d){
            cnt[d] -= cnt[b];
        }
    }

    for(int d = 1; d <= MAXVAL; ++d){
        if(cnt[d] > 0){
            cout << d << " " << cnt[d] << "\n";
        }
    }
}

}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;

        int g = __gcd(a[u], a[v]);
//        for(int d = 1; d * d <= g; ++d){
//            if(g % d == 0){
//                edges_div[d].push_back(e);
//                if(d * d != g) edges_div[g / d].push_back(e);
//            }
//        }
        Solve::edges_pos[g].emplace_back(u, v);
    }

    Solve::solve();

    return 0;
}
