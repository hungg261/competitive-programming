/******************************************************************************
Link: https://codeforces.com/contest/321/problem/C
Code: 321C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-25-20.34.49
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n;
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

char res[MAXN + 5];
bool decompose(int u, int prv, char ch){
    if(ch > 'Z') return false;

    int subsz = findSubSz(u, -1);
    int centroid = findCentroid(u, -1, subsz);

    centroidPar[centroid] = prv;
    removed[centroid] = true;

    res[centroid] = ch;

    for(int v: adj[centroid]){
        if(removed[v]) continue;
        if(!decompose(v, centroid, ch + 1))
            return false;
    }

    return true;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(!decompose(1, -1, 'A')){
        cout << "Impossible!\n";
        return 0;
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i] << ' ';
    }

    return 0;
}
