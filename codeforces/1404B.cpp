/******************************************************************************
Link: https://codeforces.com/contest/1404/problem/B
Code: 1404B
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-20-16.46.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<int> adj[MAXN + 5];

pair<int, int> farthest(int u, int prv){
    pair<int, int> best = {0, u};
    for(int v: adj[u]){
        if(v == prv) continue;

        pair<int, int> cand = farthest(v, u);
        if(cand.first + 1 > best.first)
            best = {cand.first + 1, cand.second};
    }
    return best;
}

int dist(int u, int prv, int target){
    if(u == target) return 0;

    for(int v: adj[u]){
        if(v == prv) continue;

        int d = dist(v, u, target);
        if(d != -1) return d + 1;
    }

    return -1;
}

void solve(){
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;

    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(dist(a, -1, b) <= da){
        cout << "Alice\n";
    }
    else{
        int D = farthest(farthest(1, -1).second, -1).first;
        db = min(db, D);

        if(2 * da < db) cout << "Bob\n";
        else cout << "Alice\n";
    }

    for(int i = 1; i <= n; ++i) adj[i].clear();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
