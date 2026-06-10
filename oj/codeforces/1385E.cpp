/******************************************************************************
Link: https://codeforces.com/problemset/problem/1385/E
Code: 1385E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-21-13.15.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
vector<pair<int, int>> queries;

vector<int> adj[MAXN + 5];
int indeg[MAXN + 5];

int n, m;

int Time = 0;
int pos[MAXN + 5];
bool kahn(){
    queue<int> que;
    for(int i = 1; i <= n; ++i){
        if(indeg[i] == 0) que.push(i);
    }

    while(!que.empty()){
        int u = que.front();

        if(indeg[u] == 0){
            pos[u] = ++Time;
            for(int v: adj[u]){
                --indeg[v];
                if(indeg[v] == 0) que.push(v);
            }
            que.pop();
        }
    }

    if(Time != n){
        cout << "NO\n";
        return false;
    }

    return true;
}

void solve(){
    cin >> n >> m;

    Time = 0;
    for(int i = 1; i <= n; ++i){
        adj[i].clear();
        pos[i] = 0;
        indeg[i] = 0;
    }
    queries.clear();

    for(int i = 1; i <= m; ++i){
        int a, b, type;
        cin >> type >> a >> b;

        if(type == 0){
            queries.emplace_back(a, b);
        }
        else{
            adj[a].push_back(b);
            indeg[b]++;
        }
    }

    if(!kahn()) return;

    for(pair<int, int> p: queries){
        int a, b; tie(a, b) = p;
        if(pos[a] > pos[b]) swap(a, b);

        adj[a].push_back(b);
    }

    cout << "YES\n";
    for(int u = 1; u <= n; ++u){
        for(int v: adj[u]){
            cout << u << ' ' << v << '\n';
        }
    }
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
