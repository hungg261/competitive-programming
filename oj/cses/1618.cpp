#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;

    int ans = 0;
    while(n > 0){
        n /= 5;
        ans += n;
    }

    cout << ans << '\n';

    return 0;
}
