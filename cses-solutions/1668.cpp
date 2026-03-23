#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 2e5;
int n, m;
int color[MAXN + 5];
vector<int> children[MAXN + 5];

bool bfs(int u){
    if(color[u] != -1) return true;

    queue<int> que;
    que.push(u);
    color[u] = 0;

    while(!que.empty()){
        int pupil = que.front();
        que.pop();

        for(int dest: children[pupil]){
            if(color[dest] == -1){
                color[dest] = 1 - color[pupil];
                que.push(dest);
            }
            else if(color[dest] != color[pupil]){
                continue;
            }
            else return false;
        }
    }

    return true;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    memset(color, -1, sizeof color);
    while(m--){
        int a, b;
        cin >> a >> b;

        children[a].push_back(b);
        children[b].push_back(a);
    }

    for(int node = 1; node <= n; ++node){
        if(!bfs(node)){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for(int node = 1; node <= n; ++node){
        cout << color[node] + 1 << ' ';
    }
    return 0;
}
