#include<bits/stdc++.h>
#define int long long
using namespace std;

int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}

void trau(int n){
    int ans = n;
    int ra = n, rb = n, rc = n;
    for(int a = 1; a <= n; ++a){
        for(int b = 1; b <= n; ++b){
            for(int c = 1; c <= n; ++c){
                int cur = lcm(lcm(a, b), c);
                if(cur > ans){
                    tie(ra, rb, rc) = {a, b, c};
                    ans = cur;
                }
            }
        }
    }

    cout << ans << '\n';
    cout << ra << ' ' << rb << ' ' << rc << '\n';
}

void solve(){
    int n;
    cin >> n;

    int ans = n;
    for(int c = n; c >= 1; --c){
        ans = max({ans, lcm(n * (n - 1), c), lcm((n - 1) * (n - 2), c)});
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
