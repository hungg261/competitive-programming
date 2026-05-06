/******************************************************************************
Link: https://cses.fi/problemset/task/1134
Code: 1134
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-06-23.39.01
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, deg[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    vector<int> prufer;
    for(int i = 1; i <= n - 2; ++i){
        int u; cin >> u;
        prufer.push_back(u);

        ++deg[u];
    }

    priority_queue<int, vector<int>, greater<int>> leaf;
    for(int u = 1; u <= n; ++u)
        if(!deg[u]) leaf.push(u);

    for(int u: prufer){
        int v = leaf.top(); leaf.pop();
        cout << u << " " << v << "\n";

        --deg[u];
        if(!deg[u]) leaf.push(u);
    }

    cout << n << " " << leaf.top() << "\n";

    return 0;
}
