/******************************************************************************
Link: https://cses.fi/problemset/task/2080
Code: 2080
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-25-15.53.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, k;
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
int freq[MAXN + 5];
void decompose(int u, int prv){
    int subsz = findSubSz(u, -1);
    int centroid = findCentroid(u, -1, subsz);

    centroidPar[centroid] = prv;
    removed[centroid] = true;

    freq[0] = 1;
    int maxDepth = 0;
    for(int v: adj[centroid]){
        if(removed[v]) continue;

        vector<int> depths;
        getDepths(v, centroid, 1, k, depths);

        for(int d: depths){
            res += freq[k - d];
        }

        for(int d: depths){
            ++freq[d];
            maxDepth = max(maxDepth, d);
        }
    }
    for(int d = 0; d <= maxDepth; ++d)
        freq[d] = 0;

    for(int v: adj[centroid]){
        if(removed[v]) continue;
        decompose(v, centroid);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
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
