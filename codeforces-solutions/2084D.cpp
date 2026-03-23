#include<bits/stdc++.h>
//#define int long long
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    if(n - m * k <= n / (m + 1)){
        for(int i = 0; i < n; ++i){
            cout << i % k << ' ';
        }
        cout << '\n';
    }
    else{
        for(int i = 0; i < n; ++i){
            cout << i % (n / (m + 1)) << ' ';
        }
        cout << '\n';
    }
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
