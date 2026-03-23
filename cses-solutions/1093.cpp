#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 500, MAXSUM = MAXN * (MAXN + 1) / 2;
int n;

int divide_mod(int a, int b, int mod = MOD){
    return (a % (b * mod)) / b;
}

int dp[MAXSUM / 2 + 5];
void solve(){
    int total = n * (n + 1) / 2;
    if(total & 1){
        cout << "0\n";
        return;
    }
    total >>= 1;

    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = total; j >= i; --j){
            (dp[j] += dp[j - i]) %= (MOD * 2);
        }
    }

    cout << divide_mod(dp[total], 2) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    solve();

    return 0;
}
