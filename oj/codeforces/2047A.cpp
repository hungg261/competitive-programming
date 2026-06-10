#include<bits/stdc++.h>
using namespace std;

#define int long long
int __sqrt(int n){
    int sq = sqrt(n);
    if(sq * sq == n) return sq;
    if((sq + 1) * (sq + 1) == n) return sq + 1;
    if((sq - 1) * (sq - 1) == n) return sq - 1;
    return 0;
}

void solve(){
    int n;
    cin >> n;

    int ans = 0;
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;

        sum += a;
        if(__sqrt(sum) & 1) ++ans;
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
