#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5, MAXM = 2e5;
const int INF = 1e9;
 
int n, m;
vector<unordered_set<int>> children;
vector<int> dp;
 
void bfs(int u){
    queue<pair<int, int>> que;
    que.push({u, 1});
 
    while(!que.empty()){
        int city, mov;
        tie(city, mov) = que.front();
        que.pop();
 
        if(dp[city] <= mov) continue;
        dp[city] = mov;
 
        for(int dest: children[city]){
            if(dp[dest] > mov + 1){
                que.push({dest, mov + 1});
            }
        }
    }
}
 
void trace(int u, vector<int>& res){
    res.push_back(u);
 
    for(int prev: children[u]){
        if(dp[prev] + 1 == dp[u]){
            trace(prev, res);
            return;
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
 
    children.resize(n + 1);
    dp.resize(n + 1, INF);
 
    for(int road = 1; road <= m; ++road){
        int a, b;
        cin >> a >> b;
 
        children[a].insert(b);
        children[b].insert(a);
    }
 
    bfs(1);
 
    if(dp[n] == INF){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << dp[n] << '\n';
 
        vector<int> res;
        trace(n, res);
 
        reverse(begin(res), end(res));
        for(int city: res) cout << city << ' ';
        cout << '\n';
    }
    return 0;
}