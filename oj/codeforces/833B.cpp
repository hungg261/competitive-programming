/******************************************************************************
Link: https://codeforces.com/contest/833/problem/B
Code: 833B
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-23-22.07.42
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 35000, MAXK = 50, MAXVAL = MAXN;
int n, k, a[MAXN + 5];

int L = 1, R = 0;
int freq[MAXVAL + 5];
int cnt = 0;

void add(int i){
    if(!freq[a[i]]) ++cnt;
    freq[a[i]]++;
}

void pop(int i){
    freq[a[i]]--;
    if(!freq[a[i]]) --cnt;
}

int query(int l, int r){
    while(L > l) add(--L);
    while(R < r) add(++R);
    while(L < l) pop(L++);
    while(R > r) pop(R--);

    return cnt;
}

int dp[MAXN + 5][MAXK + 5];

void computeDp(int c, int l, int r, int optL, int optR){
    if(l > r) return;

    int mid = (l + r) >> 1;
    pair<int, int> best = {INT_MIN, -1};
    for(int i = optL; i <= min(mid, optR); ++i){
        best = max(best, {dp[i - 1][c - 1] + query(i, mid), i});
    }

    dp[mid][c] = best.first;
    int opt = best.second;

    computeDp(c, l, mid - 1, optL, opt);
    computeDp(c, mid + 1, r, opt, optR);
}

void solve(){
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int c = 1; c <= k; ++c){
        computeDp(c, 1, n, 1, n);
    }

    cout << dp[n][k] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    solve();

    return 0;
}
