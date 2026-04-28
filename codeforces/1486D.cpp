/******************************************************************************
Link: https://codeforces.com/contest/1486/problem/D
Code: 1486D
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-28-18.05.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, k;
int arr[MAXN + 5];

bool check(int x) {
    vector<int> P(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        P[i] = P[i - 1] + (arr[i] >= x ? 1 : -1);
    }

    int min_pre = 1e9;
    for(int i = k; i <= n; ++i){
        min_pre = min(min_pre, P[i - k]);

        if(P[i] - min_pre > 0) return true;
    }
    return false;
}


void solve(){
    int l = 1, r = n, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res << "\n";
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
