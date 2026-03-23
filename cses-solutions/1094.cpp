#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;

    long long cur, prv;
    cin >> prv;

    --n;
    long long ans = 0;
    while(n--){
        cin >> cur;

        if(prv > cur){
            ans += prv - cur;
            cur = prv;
        }

        prv = cur;
    }

    cout << ans << '\n';
    return 0;
}
