/******************************************************************************
Link: https://codeforces.com/contest/1519/problem/D
Code: 1519D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-08-21.33.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 5000;
int a[MAXN + 5], b[MAXN + 5];
int n, pre[MAXN + 5], suf[MAXN + 5];

int expand(int l, int r, int& ans){
    int res = 0;
    while(1 <= l && r <= n){
        if(l == r) res += a[l] * b[l];
        else res += a[r] * b[l] + a[l] * b[r];
        ans = max(ans, res + pre[l - 1] + suf[r + 1]);

        --l;
        ++r;
    }

    return res;
}

void solve(){
    int ans = pre[n];
    for(int i = 1; i <= n; ++i){
        expand(i, i, ans);
        if(i + 1 <= n) expand(i, i + 1, ans);
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i] * b[i];
    for(int i = n; i >= 1; --i) suf[i] = suf[i + 1] + a[i] * b[i];

    solve();

    return 0;
}
