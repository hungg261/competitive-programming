#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int x = 0;
    for(int i = 0; i < n; ++i){
        int cur;
        cin >> cur;

        x ^= cur;
    }

    cout << "4\n";
    cout << 1 << ' ' << (n & ~1) << '\n';
    cout << 1 << ' ' << (n & ~1) << '\n';
    cout << n - 1 << ' ' << n << '\n';
    cout << n - 1 << ' ' << n << '\n';
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
