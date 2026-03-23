#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        long long y, x;
        cin >> y >> x;

        if(y <= x){
            if(x % 2 == 1){
                long long high = x * x;
                cout << high - y + 1 << '\n';;
            }
            else{
                long long low = (x-1) * (x-1);
                cout << low + y << '\n';
            }
        }
        else{
            if(y % 2 == 1){
                long long low = (y-1) * (y-1);
                cout << low + x << '\n';
            }
            else{
                long long high = y * y;
                cout << high - x + 1 << '\n';
            }
        }
    }

    return 0;
}
