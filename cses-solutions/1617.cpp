#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;

    int ans = 1;
    while(n--){
        ans = (ans * 2) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
