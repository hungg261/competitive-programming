#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b;
    cin >> a >> b;

    double mid = (a + b) / 2.0;
    double k = floor(mid / b);

    if(k == 0){
        cout << "-1\n";
        return 0;
    }

    double ans = mid / k;
    cout << fixed << setprecision(15) << ans << '\n';


    return 0;
}
