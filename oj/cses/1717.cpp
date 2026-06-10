#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    int a = 0, b = 1;
    if(n == 1) b = a;

    for(int i = 3; i <= n; ++i){
        int c = (i - 1) * (a + b) % MOD;
        a = b; b = c;
    }

    cout << b << '\n';

    return 0;
}
