#include<bits/stdc++.h>
//#define int long long
using namespace std;

const string BASE = "narek";
int SZ = BASE.size();

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        string line; cin >> line;
        for(int j = 0; j < m; ++j){
            if(find(BASE.begin(), BASE.end(), line[j]) != BASE.end())
                arr[i] += line[j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(SZ, -1000000000));
    dp[0][SZ - 1] = 0;

    for(int i = 1; i <= n; ++i){
        for(int c = 0; c < SZ; ++c) dp[i][c] = dp[i - 1][c];
        for(int c = 0; c < SZ; ++c){
            int target = (c + 1) % SZ;
            int cur = 0;

            int ssz = arr[i].size();
            for(int j = 0; j < ssz; ++j){
                --cur;

                if(arr[i][j] == BASE[target]){
                    if(target == SZ - 1){
                        cur += 10;
                    }
                    target = (target + 1) % SZ;
                }
            }

            target = (target - 1 + SZ) % SZ;
            dp[i][target] = max(dp[i][target], dp[i - 1][c] + cur);
        }
    }

    cout << *max_element(begin(dp[n]), end(dp[n])) << '\n';
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
