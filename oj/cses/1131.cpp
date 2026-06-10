#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n;
vector<int> adj[MAXN + 5];

int length[MAXN + 5];
void dfs(int node, int parent){
    for(int dest: adj[node]){
        if(dest != parent){
            length[dest] = length[node] + 1;
            dfs(dest, node);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n - 1; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    length[1] = 0;
    dfs(1, 0);

    int farthest = max_element(length + 1, length + n + 1) - length;
    memset(length, 0, sizeof length);

    dfs(farthest, 0);
    int ans = *max_element(length + 1, length + n + 1);

    cout << ans << '\n';

    return 0;
}
