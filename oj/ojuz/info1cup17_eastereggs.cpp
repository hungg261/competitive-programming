/******************************************************************************
Link: https://oj.uz/problem/view/info1cup17_eastereggs
Code: info1cup17_eastereggs
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-17-15.59.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int query(vector<int> islands);

const int MAXN = 1005;
vector<int> adj[MAXN];
vector<int> order;

void buildOrder(int n){
    order.clear();
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);

        for(int v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int findEgg (int N, vector < pair < int, int > > bridges)
{
    for(int i = 1; i <= N; i++) adj[i].clear();

    for(auto &edge: bridges){
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    buildOrder(N);

    int low = 0, high = N - 2;
    int ans = order[N - 1];

    while(low <= high){
        int mid = low + (high - low) / 2;

        vector<int> current_query;
        for(int i = 0; i <= mid; i++){
            current_query.push_back(order[i]);
        }

        if(query(current_query) == 1){
            ans = order[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}
