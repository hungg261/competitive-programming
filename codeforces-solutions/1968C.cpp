#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> x(n + 2);
    for(int i = 2; i <= n; ++i){
        cin >> x[i];
    }
    x[n + 1] = 0;

    int prev = x[2] + 1;
    cout << prev << ' ';

    for(int i = 2; i <= n; ++i){
        int minVal = x[i + 1] + 1;
        int rep = (minVal - x[i] + prev - 1) / prev;

        int cur = prev * rep + x[i];
        cout << cur << ' ';
        prev = cur;
    }

    cout << '\n';
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
