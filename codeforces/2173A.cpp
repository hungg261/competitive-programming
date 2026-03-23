#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    string S;
    cin >> S;

    int ans = 0, reach = -1;
    for(int i = 0; i < n; ++i){
        if(S[i] == '1'){
            reach = max(reach, i + k);
        }
        else if(i > reach) ++ans;
    }

    cout << ans << '\n';
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
