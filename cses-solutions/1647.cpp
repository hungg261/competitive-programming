#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXK = 18;
int a[MAXN + 5], n, table[MAXK + 1][MAXN + 5];

void compute(){
    for(int i = 1; i <= n; ++i){
        table[0][i] = a[i];
    }

    for(int k = 1; k <= MAXK; ++k){
        for(int i = 1; i + (1 << k) - 1 <= n; ++i){
            table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
        }
    }
}

int query(int l, int r){
    int len = r - l + 1;
    int bit = __lg(len);

    return min(table[bit][l], table[bit][r - (1 << bit) + 1]);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    compute();
    while(q--){
        int u, v;
        cin >> u >> v;

        cout << query(u, v) << '\n';
    }
    return 0;
}
