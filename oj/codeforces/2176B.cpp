#include<bits/stdc++.h>
//#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    string S;
    cin >> S;

    S = S + S;
    int ans = 0, cur = 0;
    for(int i = 0; i < n * 2; ++i){
        if(S[i] != '0'){
            ans = max(ans, cur);
            cur = 0;
        }
        else cur++;
    }
    ans = max(ans, cur);

    cout << ans << '\n';
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
