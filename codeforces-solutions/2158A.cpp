#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    int y, r;
    cin >> n >> y >> r;

    cout << min(n, y / 2 + r) << '\n';
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
