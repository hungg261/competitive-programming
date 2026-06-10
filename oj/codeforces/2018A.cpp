#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int &ele: arr) cin >> ele;

    int total = accumulate(begin(arr), end(arr), 0LL);
    int maxVal = *max_element(begin(arr), end(arr));

    auto check = [&](int sz){
        if(total <= sz * maxVal){
            return sz * maxVal - total <= k;
        }

        int mul = (total + sz - 1) / sz;
        return sz * mul - total <= k;
    };

    for(int i = n; i >= 1; --i){
        if(check(i)){
            cout << i << '\n';
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
