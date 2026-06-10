/******************************************************************************
Link: https://oj.uz/problem/view/JOI22_ho_t1
Code: JOI22_ho_t1
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-31-11.35.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int n, a[MAXN + 5];
int pre[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];

        pre[i] = 1;
        while(a[i] % 2 == 0){
            a[i] >>= 1;
            pre[i] <<= 1;
        }
        pre[i] += pre[i - 1];
    }

    int Q;
    cin >> Q;

    while(Q--){
        int X; cin >> X;
        cout << a[lower_bound(pre + 1, pre + n + 1, X) - pre] << "\n";
    }

    return 0;
}
