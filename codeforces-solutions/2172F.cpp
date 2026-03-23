/******************************************************************************
Link: https://codeforces.com/problemset/problem/2172/F
Code: 2172F
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-05-11.12.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int arr[MAXN + 5], n, pre[MAXN + 5], suf[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; ++i) pre[i] = __gcd(pre[i - 1], arr[i]);
    for(int i = n; i >= 1; --i) suf[i] = __gcd(suf[i + 1], arr[i]);

    long long res = 0;
    for(int i = 1; i <= n; ++i){
        res += min(pre[i], suf[i]);
    }
    res -= pre[n];

    cout << res << '\n';

    return 0;
}
