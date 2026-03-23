/******************************************************************************
Link: https://cses.fi/problemset/task/2191
Code: 2191
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-25-00.49.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; ++i)
        cin >> p[i].first >> p[i].second;

    int ans = (p[n - 1].second + p[0].second) * (p[n - 1].first - p[0].first);
    for(int i = 0; i < n - 1; ++i){
        ans += (p[i].second + p[i + 1].second) * (p[i].first - p[i + 1].first);
    }

    cout << llabs(ans) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("2191.INP","r",stdin);
    //freopen("2191.OUT","w",stdout);

    solve();

    return 0;
}
