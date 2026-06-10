/******************************************************************************
Link: https://oj.vnoi.info/problem/sqrt_a
Code: sqrt_a
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-07-16.05.06
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int BLOCKSIZE = 448;
const int MAXN = 2e5;

int blocks[BLOCKSIZE + 5];
int arr[MAXN + 5], n, q;

void update(int idx, int val){
    int blockID = (idx - 1) / BLOCKSIZE + 1;
    blocks[blockID] += val - arr[idx];
    arr[idx] = val;
}

int get(int l, int r){
    int blockL = (l - 1) / BLOCKSIZE + 1;
    int blockR = (r - 1) / BLOCKSIZE + 1;

    int ans = 0;
    for(int b = blockL + 1; b <= blockR - 1; ++b){
        ans += blocks[b];
    }

    if(blockL == blockR){
        for(int i = l; i <= r; ++i) ans += arr[i];
    }
    else{
        for(int i = l; i <= blockL * BLOCKSIZE; ++i) ans += arr[i];
        for(int i = (blockR - 1) * BLOCKSIZE + 1; i <= r; ++i) ans += arr[i];
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("sqrt_a.INP","r",stdin);
    //freopen("sqrt_a.OUT","w",stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        int val;
        cin >> val;

        update(i, val);
    }

    for(int i = 1; i <= 10; ++i) cerr << blocks[i] << ' ';  cerr << '\n';

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int k, u;
            cin >> k >> u;

            update(k, u);
        }
        else{
            int a, b;
            cin >> a >> b;

            cout << get(a, b) << '\n';
        }
    }

    return 0;
}
