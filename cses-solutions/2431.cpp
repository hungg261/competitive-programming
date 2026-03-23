#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long k;
    cin >> k;

    long long luythua10 = 1;
    int so_chu_so = 1;

    long long di_qua = 0;
    while(k > 9 * luythua10 * so_chu_so){
        k -= 9 * luythua10 * so_chu_so;
        di_qua += 9 * luythua10;

        ++so_chu_so;
        luythua10 *= 10;
    }

    long long owner = di_qua + (k + so_chu_so - 1) / so_chu_so;
    int fixed_index = (k + so_chu_so - 1) % so_chu_so;

    cout << to_string(owner)[fixed_index] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
