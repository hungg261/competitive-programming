#include<bits/stdc++.h>
using namespace std;

#define int long long
void solve(){
    int x, y;
    cin >> x >> y;

    if(x == y){
        cout << "-1\n";
        return;
    }
    if(x < y) swap(x, y);

    auto check = [&x, &y](int k){
        return ((x + k) & (y + k)) == 0;
    };

    for(int bit = 59; bit >= 0; --bit){
        int target = 1LL << bit;
        int k = target - x;

        if(check(k)){
            cout << k << '\n';
            return;
        }
    }

    cout << "-1\n";
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
