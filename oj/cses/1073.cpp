#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& ele: a) cin >> ele;

    vector<int> dp = {a[0]};
    for(int i = 1; i < n; ++i){
        if(dp.back() <= a[i]){
            dp.push_back(a[i]);
        }
        else{
            *upper_bound(begin(dp), end(dp), a[i]) = a[i];
        }
    }

    cout << dp.size() << '\n';

    return 0;
}
