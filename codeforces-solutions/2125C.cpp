#include<bits/stdc++.h>
#define int long long
using namespace std;

int exprimes[4] = {2, 3, 5, 7};
int ep = 4;
int cnt(int n){
    int ans = 0;
    for(int mask = 1; mask < (1 << ep); ++mask){
        int tich = 1, bit = 0;
        for(int i = 0; i < ep; ++i){
            if(mask >> i & 1){
                tich *= exprimes[i];
                ++bit;
            }
        }

        if(bit & 1) ans += n / tich;
        else ans -= n / tich;
    }

    return ans;
}

void solve(){
    int l, r;
    cin >> l >> r;

    cout << (r - l + 1) - (cnt(r) - cnt(l - 1)) << '\n';
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
