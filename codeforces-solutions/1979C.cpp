#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> k(n);
    for(int& ele: k) cin >> ele;

    auto check = [&](int mid){
        int sum = 0;
        for(int ele: k){
            sum += (mid + ele) / ele;
        }
        return mid >= sum;
    };

    int l = 1, r = 1e9;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            for(int i = 0; i < n; ++i){
                cout << (mid + k[i]) / k[i] << ' ';
            } cout << '\n';
            return;
        }
        else{
            l = mid + 1;
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
