#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    bool r1 = false;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        int cur;
        cin >> cur;

        r1 |= cur % 3 == 1;
        sum += cur;
    }

    if(sum % 3 == 0) cout << "0\n";
    else if(sum % 3 == 1) cout << (r1 ? 1 : 2) << '\n';
    else cout << "1\n";
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
