/******************************************************************************
Link: https://oj.vnoi.info/problem/hsg_hcm_v2_25_sodep
Code: hsg_hcm_v2_25_sodep
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-09-10.52.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int extended_gcd(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return g;
}

void solve(){
    int K;
    cin >> K;

    if(K == 1){
        cout << "1 1\n";
        return;
    }

    int x0, y0;
    int g = extended_gcd(9, K, x0, y0);

    if(g != 1){
        cout << "-1\n";
        return;
    }

    int b = (x0 % K + K) % K;
    int S = 9 * b;
    int f = K - 1;

    if(f > 8){
        f -= 8;
        S += 8;
    }

    S += f % 9 + (f / 9) * 9;
    f %= 9;

    cout << f << " " << S << "\n";

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SODEP.INP","r",stdin);
    freopen("SODEP.OUT","w",stdout);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
