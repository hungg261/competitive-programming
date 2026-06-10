/******************************************************************************
Link: https://codeforces.com/contest/1370/problem/D
Code: 1370D
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-28-14.23.57
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, k;
int arr[MAXN + 5];

bool check(int x){
    int len[2] = {};
    for(int i = 1; i <= n; ++i){
        for(int m = 0; m < 2; ++m){
            if(len[m] % 2 == m || arr[i] <= x)
                ++len[m];

            if(len[m] >= k) return true;
        }
    }

    return false;
}

void solve(){
    int l = 1, r = 1e9, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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
