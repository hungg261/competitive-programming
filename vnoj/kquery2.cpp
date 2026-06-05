/******************************************************************************
Link: https://oj.vnoi.info/problem/kquery2
Code: kquery2
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-05-09.10.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

const int MAXN = 3e4, MAXQ = 2e5, MAXBLOCK = sqrt(MAXN) + 5, MAXVAL = 1e4;
int BLOCKSIZE;
int n, q, a[MAXN + 5];

FenwickTree blocks[MAXBLOCK + 1];

void update(int pos, int x){
    int b = (pos + BLOCKSIZE - 1) / BLOCKSIZE;

    if(a[pos]) blocks[b].update(a[pos], -1);
    blocks[b].update(a[pos] = x, 1);
}

int query(int l, int r, int k){
    int blockL = (l + BLOCKSIZE - 1) / BLOCKSIZE,
        blockR = (r + BLOCKSIZE - 1) / BLOCKSIZE;

    int res = 0;
    for(int i = blockL + 1; i <= blockR - 1; ++i){
        res += blocks[i].get(k + 1, MAXVAL);
    }

    if(blockL == blockR){
        for(int i = l; i <= r; ++i){
            if(a[i] > k) ++res;
        }
    }
    else{
        for(int i = l; i <= blockL * BLOCKSIZE; ++i)
            res += a[i] > k;
        for(int i = (blockR - 1) * BLOCKSIZE + 1; i <= r; ++i)
            res += a[i] > k;
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    BLOCKSIZE = sqrt(n);
    if(BLOCKSIZE == 0) BLOCKSIZE = 1;

    for(int i = 1; i <= MAXBLOCK; ++i)
        blocks[i] = FenwickTree(MAXVAL + 1);

    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        update(i, cur);
    }

    cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 0){
            int u, x;
            cin >> u >> x;

            update(u, x);
        }
        else{
            int l, r, k;
            cin >> l >> r >> k;

            cout << query(l, r, k) << "\n";
        }
    }

    return 0;
}
