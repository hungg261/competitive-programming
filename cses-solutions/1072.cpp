#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n;
    cin >> n;

    for(long long k = 1; k <= n; ++k){
        long long S = k * k;
        cout << S * (S - 1) / 2 - (k - 2) * (k - 1) * 4 << '\n';
    }

    return 0;
}
