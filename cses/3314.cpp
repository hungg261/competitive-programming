#include<bits/stdc++.h>
using namespace std;

vector<int> L, R;
int n;
vector<int> h;

void compute(){
    vector<int> sta;
    for(int i = 1; i <= n; ++i){
        while(!sta.empty() && h[sta.back()] <= h[i]) sta.pop_back();
        L[i] = sta.empty() ? 0 : sta.back();

        sta.push_back(i);
    }

    sta.clear();
    for(int i = n; i >= 1; --i){
        while(!sta.empty() && h[sta.back()] <= h[i]) sta.pop_back();
        R[i] = sta.empty() ? n + 1 : sta.back();

        sta.push_back(i);
    }
}

vector<int> dp;
int solve(int idx){
    if(idx <= 0 || idx > n) return 0;
    if(dp[idx] != -1) return dp[idx];

    return dp[idx] = max(solve(L[idx]), solve(R[idx])) + 1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    h.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> h[i];
    }

    L.resize(n + 1); R.resize(n + 1);
    compute();

    dp.resize(n + 1, -1);
    int ans = 1;
    for(int i = 1; i <= n; ++i) ans = max(ans, solve(i));

    cout << ans << '\n';

    return 0;
}
