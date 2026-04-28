/******************************************************************************
Link: https://codeforces.com/contest/448/problem/C
Code: 448C
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-28-16.13.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
int n, arr[MAXN + 5];

int solve(int l, int r, int delta){
    if(l > r) return 0;

    int minVal = *min_element(arr + l, arr + r + 1);

    int res = minVal - delta;
    delta = minVal;

    int last = l;
    for(int i = l; i <= r; ++i){
        if(arr[i] == minVal){
            res += solve(last, i - 1, delta);
            last = i + 1;
        }
    }
    res += solve(last, r, delta);

    return min(res, r - l + 1);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    cout << solve(1, n, 0) << "\n";

    return 0;
}
