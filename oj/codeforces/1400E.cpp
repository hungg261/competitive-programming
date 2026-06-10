/******************************************************************************
Link: https://codeforces.com/contest/1400/problem/E
Code: 1400E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-25-11.41.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
int a[MAXN + 5], n;

int solve(int l, int r, int h){
    if(l > r) return 0;

    int minVal = *min_element(a + l, a + r + 1);
    int res = minVal - h;

    int last = l;
    for(int k = l; k <= r; ++k){
        if(a[k] == minVal){
            res += solve(last, k - 1, minVal);
            last = k + 1;
        }
    }
    res += solve(last, r, minVal);

    return min(r - l + 1, res);
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
