/******************************************************************************
Link: https://marisaoj.com/problem/504
Code: 504
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-08-10.01.12
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

const int MAXN = 1e5, MAXQ = 1e5, MAXVAL = 1e5, MAXBLOCK = 350;
int n, q, arr[MAXN + 5];

struct Query{
    int l, r, a, b, id;

    static int Counter;

    friend istream& operator >> (istream& is, Query& qr){
        qr.id = ++Counter;
        return is >> qr.l >> qr.r >> qr.a >> qr.b;
    }

    bool operator < (const Query& other) const {
        int bL = (l + MAXBLOCK - 1) / MAXBLOCK,
            bR = (other.l + MAXBLOCK - 1) / MAXBLOCK;

        if(bL != bR) return bL < bR;
        return (bL & 1) ? r < other.r : r > other.r;
    }
} queries[MAXQ + 5];
int Query::Counter = 0;

int L = 1, R = 0;
FenwickTree mark(MAXVAL), dmark(MAXVAL);

void add(int x){
    if(mark.get(x, x) == 0) dmark.update(x, 1);
    mark.update(x, 1);
}

void pop(int x){
    mark.update(x, -1);
    if(mark.get(x, x) == 0) dmark.update(x, -1);
}

void solve(){
    sort(queries + 1, queries + q + 1);
    vector<pair<int, int>> res(q + 1);
    for(int i = 1; i <= q; ++i){
        const Query& qr = queries[i];
        while(L > qr.l) add(arr[--L]);
        while(R < qr.r) add(arr[++R]);
        while(L < qr.l) pop(arr[L++]);
        while(R > qr.r) pop(arr[R--]);

        res[qr.id] = {mark.get(qr.a, qr.b), dmark.get(qr.a, qr.b)};
    }

    for(int i = 1; i <= q; ++i){
        cout << res[i].first << " " << res[i].second << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    for(int i = 1; i <= q; ++i){
        cin >> queries[i];
    }

    solve();

    return 0;
}
