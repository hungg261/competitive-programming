/******************************************************************************
Link: https://codeforces.com/problemset/problem/1175/F
Code: 1175F
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-11-17.56.31
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 3e5;
int n, a[MAXN + 5];
uint64_t pre[MAXN + 5];

uint64_t h[MAXN + 5], cpre[MAXN + 5];
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

uint64_t get(uint64_t P[], int l, int r){
    return P[r] ^ P[l - 1];
}

int calc(){
    int res = 0;

    int i = 1;
    while(i <= n){
        if(a[i] == 1){
            int j = i + 1;
            int len = 1;
            while(j <= n && a[j] != 1){
                len = max(len, a[j]);
                res += get(pre, j - len + 1, j) == get(cpre, 1, len);

                ++j;
            }

            i = j - 1;
        }

        ++i;
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cpre[i] = cpre[i - 1] ^ (h[i] = rng());

    int res = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] ^ h[a[i]];

        res += a[i] == 1;
    }

    res += calc();
    reverse(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] ^ h[a[i]];
    res += calc();

    cout << res << '\n';

    return 0;
}
