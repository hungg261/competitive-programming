#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
long long INF = LLONG_MAX;
int n, m;
vector<pair<int,int>> routes[MAXN + 1];

void solve(){
    vector<long long> res(n + 1, INF);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 1});

    while(!pq.empty()){
        int city;
        long long cost;
        tie(cost, city) = pq.top();
        pq.pop();

        if(cost >= res[city]) continue;
        res[city] = cost;

        for(pair<int, int> dest: routes[city]){
            long long new_cost = cost + dest.second;
            if(new_cost < res[dest.first]){
                pq.push({new_cost, dest.first});
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i] << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        routes[a].push_back(make_pair(b, c));
    }

    solve();
    return 0;
}
