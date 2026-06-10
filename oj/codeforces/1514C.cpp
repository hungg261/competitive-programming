#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> res;
    int prod = 1;
    for(int i = 1; i < n; ++i){
        if(__gcd(i, n) == 1){
            res.push_back(i);
            prod = prod * i % n;
        }
    }

    if(prod != 1) res.erase(find(begin(res), end(res), prod));

    cout << res.size() << '\n';
    for(int ele: res) cout << ele << ' ';
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
