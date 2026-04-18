/******************************************************************************
Link: https://codeforces.com/contest/1400/problem/D
Code: 1400D
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-16-20.38.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1), mark(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    long long res = 0;
    for(int i = n; i >= 1; --i){
        int found = 0;
        for(int j = i - 1; j >= 1; --j){
            if(a[j] == a[i]){
                res += found;
            }

            found += mark[a[j]];
        }

        ++mark[a[i]];
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
