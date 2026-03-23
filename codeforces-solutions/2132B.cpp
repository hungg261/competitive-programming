#include<bits/stdc++.h>
using namespace std;

#define int long long

int power(int a, int b){
    int res = 1;
    while(b--) res *= a;
    return res;
}

void solve(){
    int n;
    cin >> n;

    vector<int> res;
    for(int i = 18; i > 0; --i){
        int c = power(10, i) + 1LL;
        if(n % c == 0){
            res.push_back(n / c);
        }
    }

    cout << res.size() << '\n';
    if(!res.empty()) { for(int ele: res) cout << ele << ' '; cout << '\n'; }
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
