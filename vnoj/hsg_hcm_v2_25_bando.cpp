/******************************************************************************
Link: https://oj.vnoi.info/problem/hsg_hcm_v2_25_bando
Code: hsg_hcm_v2_25_bando
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-09-15.57.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6, MAXK = 1e6;
int freq[MAXN + 5];

struct DSU{
    vector<int> par, sz, val;
    int n;

    DSU(int _n): n(_n){
        par.resize(n + 1);
        sz.resize(n + 1);
        val.resize(n + 1);

        for(int u = 0; u <= n; ++u)
            create(u);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
        val[v] = v;
    }

    int find(int v){
        return par[v] == v ? v : (par[v] = find(par[v]));
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            val[a] = val[b];
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];
        }
    }

    int at(int i){ return val[find(i)]; }
};

int N, K;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BANDO.INP","r",stdin);
    freopen("BANDO.OUT","w",stdout);

    cin >> N >> K;

    DSU dsu(N);

    int L = 0, R = N;
    for(int i = 1; i <= K; ++i){
        int x; cin >> x;

        int pos = dsu.at(x);
        int left = pos - L, right = R - pos;
        if(left <= right){
            for(int j = 1; j <= left; ++j){
                dsu.unite(pos - j, pos + j);
            }
            L = pos;
        }
        else{
            for(int j = 1; j <= right; ++j){
                dsu.unite(pos + j, pos - j);
            }
            R = pos;
        }

    }


    for(int i = 0; i <= N; ++i){
        ++freq[dsu.at(i)];
    }

    cout << R - L + 1 << "\n";
    for(int i = L; i <= R; ++i){
        cout << freq[i] << " ";
    }

    return 0;
}
