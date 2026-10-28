/******************************************************************************
Link: https://www.codechef.com/START262C/problems/EQLZR
Code: EQLZR
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-28-21.39.15
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e9;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> d(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }

    int l = -1;
    for(int i = 2; i <= n; ++i){
        if(d[i] == -1){
            ++d[i];
            l = i;
            break;
        }
    }
    if(l == -1) ++d[1], l = 1;

    for(int i = n; i > l; --i){
        if(d[i] == 1){
            --d[i];
            break;
        }
    }

    int res = 0;
    for(int i = 2; i <= n; ++i){
        if(d[i] == 0) ++res;
    }

    cout << res << "\n";
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
