#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    int k = __lg(n) + 1;
    vector<vector<int>> table(n + 1, vector<int>(k + 1));
    for(int i = 1; i <= n; ++i) table[i][0] = abs(arr[i - 1] - arr[i]);

    for(int j = 1; j <= k; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            table[i][j] = __gcd(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
        }
    }

    auto queryGCD = [&table](int l, int r){
        if(l > r) return 0LL;

        int bit = __lg(r - l + 1);
        return __gcd(table[l][bit], table[r - (1 << bit) + 1][bit]);
    };

    while(q--){
        int l, r;
        cin >> l >> r;

        cout << queryGCD(l + 1, r) << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
