/******************************************************************************
Link: https://codeforces.com/problemset/problem/868/F
Code: 868F
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-31-21.40.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5, MAXK = 20, INF = 1e18;
int dp[MAXK + 5][MAXN + 5];
int n, k, arr[MAXN + 5];

int mark[MAXN + 5];
int cost = 0;
int L = 1, R = 0;

void add(int x){
    cost += mark[x];
    mark[x]++;
}
void pop(int x){
    --mark[x];
    cost -= mark[x];
}

void move(int l, int r){
    while(L > l) add(arr[--L]);
    while(R < r) add(arr[++R]);
    while(L < l) pop(arr[L++]);
    while(R > r) pop(arr[R--]);
}

void compute(int c, int l, int r, int optL, int optR){
    if(l > r) return;

    int mid = (l + r) >> 1;
    pair<int, int> best = {INF, -1};

    for(int j = optL; j <= min(mid, optR); ++j){
        move(j, mid);
        int val = dp[c - 1][j - 1] + cost;
        if(val < best.first){
            best = {val, j};
        }
    }

    dp[c][mid] = best.first;
    int opt = best.second;

    compute(c, l, mid - 1, optL, opt);
    compute(c, mid + 1, r, opt, optR);
}

void solve(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int c = 1; c <= k; ++c){
        memset(mark, 0, sizeof mark);
        cost = 0;
        L = 1; R = 0;

        compute(c, 1, n, 1, n);
    }

    cout << dp[k][n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    solve();

    return 0;
}
