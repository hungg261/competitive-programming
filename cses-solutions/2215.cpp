#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    for(int i = n - k + 1; i <= n; ++i) cout << i << ' ';
    for(int i = n - k; i >= 1; --i) cout << i << ' ';
    cout << '\n';
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
