#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100, MAXVAL = 1000;
const int MAXSUM = MAXN * MAXVAL;
int n, a[MAXN + 5];
bool dp[MAXSUM + 5];

void solve(){
    dp[0] = true;
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;

        for(int j = MAXSUM; j >= cur; --j){
            dp[j] |= dp[j - cur];
        }
    }

    vector<int> res;
    for(int v = 1; v <= MAXSUM; ++v){
        if(dp[v]){
            res.push_back(v);
        }
    }

    cout << res.size() << '\n';
    for(int ele: res) cout << ele << ' ';
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    solve();

    return 0;
}
