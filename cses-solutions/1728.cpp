/******************************************************************************
Link: https://cses.fi/problemset/task/1728
Code: 1728
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-29-20.47.31
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define double long double
#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1728.INP","r",stdin);
    //freopen("1728.OUT","w",stdout);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    double ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            int total = 0;
            for(int k = 1; k <= arr[i]; ++k){
                total += min(k - 1, arr[j]);
            }

            ans += 1.0 * total / (arr[i] * arr[j]);
        }
    }

    cout << fixed << setprecision(6) << ans << '\n';

    return 0;
}
