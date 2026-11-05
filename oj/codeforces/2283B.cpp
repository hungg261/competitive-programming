/******************************************************************************
Link: https://codeforces.com/contest/2283/problem/B
Code: 2283B
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-04-21.57.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int ans = n - 1;
    for(int i = 0; i < n; ++i){
        int res = 0;
        for(int j = 0; j < n; ++j){
            if(a[j] % a[i] == 0){}
            else{
                ++res;
            }
        }

        ans = min(ans, res);
    }

    cout << ans << "\n";
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
