#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int powmod(int a, int b, int m){
    int res = 1 % m;
    a %= m;

    while(b > 0){
        if(b % 2 == 1){
            res = (long long)res * a % m;
        }
        a = (long long)a * a % m;
        b /= 2;
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;

        cout << powmod(a, b, MOD) << '\n';
    }
    return 0;
}
