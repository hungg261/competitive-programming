#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> pre(n + 1);
    iota(begin(pre), end(pre), 0);

    pre[r] = pre[l - 1];
    for(int i = 1; i <= n; ++i){
        int cur = pre[i] ^ pre[i - 1];
        cout << cur << ' ';
    }
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
