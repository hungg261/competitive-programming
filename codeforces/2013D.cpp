/******************************************************************************
Link: https://codeforces.com/contest/2013/problem/D
Code: 2013D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-11-17.58.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    vector<pair<int, int>> sta;
    for(int i = 1; i <= n; ++i){
        int sum = arr[i], cnt = 1;
        while(!sta.empty() && sta.back().first > sum / cnt){
            sum += sta.back().first * (sta.back().second);
            cnt += sta.back().second;
            sta.pop_back();
        }

        sta.emplace_back(sum / cnt, cnt - sum % cnt);
        if(sum % cnt > 0) sta.emplace_back(sum / cnt + 1, sum % cnt);
    }

    int mn = 1e18, mx = -1e18;
    for(const pair<int, int>& p: sta){
        mn = min(mn, p.first);
        mx = max(mx, p.first);
    }

    cout << mx - mn << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
