/******************************************************************************
Link: https://codeforces.com/contest/1242/problem/B
Code: 1242B
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-29-10.24.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, m;
set<int> removed[MAXN + 5], unvisited;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        removed[a].insert(b);
        removed[b].insert(a);
    }

    for(int i = 1; i <= n; ++i)
        unvisited.insert(i);

    int cc = 0;
    while(!unvisited.empty()){
        auto it = unvisited.begin();

        queue<int> que;
        que.push(*it);

        unvisited.erase(it);

        ++cc;

        while(!que.empty()){
            int u = que.front(); que.pop();

            vector<int> nxt;
            for(int v: unvisited){
                if(removed[u].find(v) == removed[u].end()){
                    nxt.push_back(v);
                    que.push(v);
                }
                else{
                    removed[u].erase(v);
                    removed[v].erase(u);
                }
            }

            for(int v: nxt)
                unvisited.erase(v);
        }
    }

    cout << cc - 1 << "\n";

    return 0;
}
