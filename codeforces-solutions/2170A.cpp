#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> arr(n + 2, vector<int>(n + 2, 0));
    for(int i = 1; i <= n * n; ++i){
        arr[(i - 1) / n + 1][(i - 1) % n + 1] = i;
    }

    auto around = [&arr](int x, int y){
        return arr[x][y] + arr[x - 1][y] + arr[x + 1][y] + arr[x][y - 1] + arr[x][y + 1];
    };

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            ans = max(ans, around(i, j));
        }
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
