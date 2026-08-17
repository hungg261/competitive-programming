/******************************************************************************
Link: https://oj.vnoi.info/problem/hsg_bn_v2_25_seqcp
Code: hsg_bn_v2_25_seqcp
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-17-08.07.49
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 70'000, MAXVAL = 70'000;
int n, q, a[MAXN + 5];
bitset<MAXVAL> pre[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("seqcp.INP","r",stdin);
    freopen("seqcp.OUT","w",stdout);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];

        pre[i] = pre[i - 1];

        int temp = a[i];
        for(int j = 2; j * j <= temp; ++j){
            int c = 0;
            while(temp % j == 0){
                c ^= 1;
                temp /= j;
            }

            pre[i][j] = (int)pre[i][j] ^ c;
        }
        if(temp > 1){
            pre[i][temp] = (int)pre[i][temp] ^ 1;
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        cout << ((pre[r] ^ pre[l - 1]).count() == 0 ? "YES" : "NO") << "\n";
    }

    return 0;
}
