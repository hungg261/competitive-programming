#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;

    if(a > b) swap(a, b);
    int diff = b - a;

    if(a >= diff && (a - diff) % 3 == 0){
        cout << "YES\n";
    }
    else cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
