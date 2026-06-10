/******************************************************************************
Link: https://codeforces.com/contest/484/problem/B
Code: 484B
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-02-11.56.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXVAL = 1e6 + 5, MAXLG = __lg(MAXVAL) + 1;
int n, a[MAXN + 5], pre[MAXVAL * 2 + 5];

void solve(){
    int res = 0;
    for(int i = 2; i <= MAXVAL; ++i){
        if(pre[i] == i) for(int j = i; j + i < MAXVAL * 2; j += i){
            int v = j + i - 1;
            if(pre[v] >= j)
                res = max(res, pre[v] - j);
        }
    }

    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[a[i]] = a[i];
    }

    for(int v = 1; v <= MAXVAL * 2; ++v){
        pre[v] = max(pre[v], pre[v - 1]);
    }

    solve();

    return 0;
}
