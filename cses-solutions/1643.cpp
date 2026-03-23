#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    long long cur = -1e15, ans = -1e15;

    for(int i = 1; i <= n; ++i){
        long long x; cin >> x;

        cur = max(cur + x, x);
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}
