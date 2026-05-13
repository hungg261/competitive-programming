/******************************************************************************
Link: https://codeforces.com/contest/1977/problem/C
Code: 1977C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-12-17.53.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXVAL = 1e9 + 5;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    sort(begin(a) + 1, end(a));

    int l = 1;
    for(int i = 1; i <= n; ++i){
        if((l = l * a[i] / __gcd(l, a[i])) > a[n]){
            cout << n << "\n";
            return;
        }
    }

    auto check = [&](int lcm) -> int {
        if(binary_search(begin(a) + 1, end(a), lcm)) return -1;

        int curlcm = 1;
        int len = 0;
        for(int i = 1; i <= n; ++i){
            if(lcm % a[i] == 0){
                curlcm = curlcm * a[i] / __gcd(curlcm, a[i]);
                ++len;
            }
        }

        return curlcm == lcm ? len : -1;
    };

    int ans = 0;
    for(int d = 1; d * d <= a[n]; ++d){
        if(a[n] % d == 0){
            ans = max(ans, check(d));
            ans = max(ans, check(a[n] / d));
        }
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
