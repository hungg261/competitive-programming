/******************************************************************************
Link: https://codeforces.com/contest/1400/problem/E
Code: 1400E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-25-13.55.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
int a[MAXN + 5], n;

int solve(int l, int r, int h){
    if(l > r) return 0;

    int mid = min_element(a + l, a + r + 1) - a;
    return min(r - l + 1, solve(l, mid - 1, a[mid])
                        + solve(mid + 1, r, a[mid]) + a[mid] - h);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    cout << solve(1, n, 0) << "\n";

    return 0;
}
