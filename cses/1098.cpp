#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int ans = 0;
    while(n--){
        int cur; cin >> cur;
        ans ^= cur % 4;
    }

    cout << (ans != 0 ? "first" : "second") << '\n';
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
