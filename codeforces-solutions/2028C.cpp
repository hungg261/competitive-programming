#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m, v;
    cin >> n >> m >> v;

    vector<int> arr(n + 1), pre(n + 1, 0), preCnt(n + 1), sufCnt(n + 2);

    int S = 0;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
        S += arr[i];
    }

    preCnt[0] = 0;
    int sumL = 0, cntL = 0;
    for(int i = 1; i <= n; ++i){
        if(sumL + arr[i] >= v){
            ++cntL;
            sumL = 0;
        }
        else sumL += arr[i];
        preCnt[i] = cntL;
    }

    sufCnt[n + 1] = 0;
    int sumR = 0, cntR = 0;
    for(int i = n; i >= 1; --i){
        if(sumR + arr[i] >= v){
            ++cntR;
            sumR = 0;
        }
        else sumR += arr[i];
        sufCnt[i] = cntR;
    }

    int ans = -1;
    for(int i = 1; i <= n; ++i){
        int idx = lower_bound(begin(preCnt), end(preCnt), m - sufCnt[i + 1]) - begin(preCnt);
        if(idx <= i) ans = max(ans, pre[i] - pre[idx]);
    }

    cout << ans << '\n';
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
