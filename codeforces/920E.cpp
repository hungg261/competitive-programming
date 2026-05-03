/******************************************************************************
Link: https://codeforces.com/contest/920/problem/E
Code: 920E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-03-11.29.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500000;
int n, m;
vector<int> removed[MAXN + 5];
set<int> unvisited;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        removed[a].push_back(b);
        removed[b].push_back(a);
    }

    for(int u = 1; u <= n; ++u){
        unvisited.insert(u);

        sort(begin(removed[u]), end(removed[u]));
    }

    vector<vector<int>> cc;
    while(!unvisited.empty()){
        auto it = unvisited.begin();

        queue<int> que;
        que.push(*it);

        unvisited.erase(it);

        vector<int> sz;
        while(!que.empty()){
            int u = que.front(); que.pop();
            sz.push_back(u);

            vector<int> nxt;
            for(int v: unvisited){
                if(!binary_search(begin(removed[u]), end(removed[u]), v))
                    nxt.push_back(v);
            }

            for(int v: nxt){
                unvisited.erase(v);
                que.push(v);
            }
        }

        cc.push_back(sz);
    }

    sort(begin(cc), end(cc));

    cout << cc.size() << "\n";
    for(const vector<int>& sz: cc){
        cout << sz.size() << " ";
        for(int u: sz) cout << u << " ";
        cout << "\n";
    }

    return 0;
}
