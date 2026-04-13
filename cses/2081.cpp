/******************************************************************************
Link: https://cses.fi/problemset/task/2081
Code: 2081
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-13-10.18.31
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    void assign(int idx, int val){
        update(idx, val - at(idx));
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ l = max(1, l); r = min(n, r); return get(r) - get(l - 1); }
    int at(int i){ return get(i, i); }
};

const int MAXN = 2e5;
int n, k1, k2;
vector<int> adj[MAXN + 5];
int Sz[MAXN + 5];
int removed[MAXN + 5];
int centroidPar[MAXN + 5];

int findSubSz(int u, int prv){
    int depth = 1;
    for(int v: adj[u]){
        if(v == prv || removed[v]) continue;

        depth += findSubSz(v, u);
    }

    return Sz[u] = depth;
}

int findCentroid(int u, int prv, int subsz){
    for(int v: adj[u]){
        if(v == prv || removed[v]) continue;

        if(Sz[v] > subsz / 2)
            return findCentroid(v, u, subsz);
    }

    return u;
}

void getDepths(int u, int prv, int depth, int k, vector<int>& depths){
    if(depth > k) return;
    depths.push_back(depth);

    for(int v: adj[u]){
        if(v == prv || removed[v]) continue;
        getDepths(v, u, depth + 1, k, depths);
    }
}

long long res = 0;
FenwickTree freq(MAXN + 1);
void decompose(int u, int prv){
    int subsz = findSubSz(u, -1);
    int centroid = findCentroid(u, -1, subsz);

    centroidPar[centroid] = prv;
    removed[centroid] = true;

    freq.update(0, 1);
    int maxDepth = 0;
    for(int v: adj[centroid]){
        if(removed[v]) continue;

        vector<int> depths;
        getDepths(v, centroid, 1, k2, depths);

        for(int d: depths){
            res += freq.get(k1 - d, k2 - d);
        }

        for(int d: depths){
            freq.update(d, 1);
            maxDepth = max(maxDepth, d);
        }
    }
    for(int d = 0; d <= maxDepth; ++d)
        freq.assign(d, 0);

    for(int v: adj[centroid]){
        if(removed[v]) continue;
        decompose(v, centroid);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k1 >> k2;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    decompose(1, -1);

    cout << res << '\n';

    return 0;
}
