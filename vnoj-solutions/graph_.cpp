#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
int n, m;
vector<int> adj[MAXN + 5];

int num[MAXN + 5], low[MAXN + 5];

int order = 0;
bool is_khop[MAXN + 5];
int cau = 0;
void dfs(int u, int prev){
    num[u] = low[u] = ++order;
    int child = 0;
    for(int v: adj[u]){
        if(v == prev) continue;
        
        if(!num[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            
            if(low[v] == num[v]) ++cau;
            
            ++child;
            if(u == prev){ if(child > 1) is_khop[u] = true; }
            else if(low[v] >= num[u]) is_khop[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= n; ++i){
        if(!num[i]) dfs(i, i);
    }
    
    int khop = 0;
    for(int i = 1; i <= n; ++i) khop += is_khop[i];
    
    cout << khop << ' ' << cau << '\n';
        
    return 0;
}
