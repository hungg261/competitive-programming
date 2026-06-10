#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for(int& ele: A) cin >> ele;
    for(int& ele: B) cin >> ele;
    vector<int> pairsum;

    for(int i = 0; i < n; ++i){
        pairsum.push_back(A[i] + B[i] - 2);
    }
    sort(begin(pairsum), end(pairsum), greater<int>());

    int ans = - (accumulate(begin(B), end(B), 0LL) - n);
    for(int i = 0; i < n; i += 2){
        ans += pairsum[i];
    }

    cout << ans << '\n';
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
