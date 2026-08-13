/******************************************************************************
Link: https://judge.yosupo.jp/problem/static_range_frequency
Code: static_range_frequency
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-12-09.50.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5, MAXQ = 5e5, MAXBLOCK = 700;
int n, q, a[MAXN + 5];

struct Query{
    int l, r, x, id;

    void input(int i){
        cin >> l >> r >> x;
        --r;

        id = i;
    }

    bool operator < (const Query& other){
        int bL = l / MAXBLOCK,
            bR = other.l / MAXBLOCK;

        if(bL != bR) return bL < bR;
        return (bL & 1) ? r < other.r : r > other.r;
    }
} queries[MAXQ + 5];

vector<int> values;
int f(int x){ return lower_bound(begin(values), end(values), x) - begin(values); }
int freq[MAXN + 5];

int L = 0, R = -1;
void add(int x){ ++freq[a[x]]; }
void pop(int x){ --freq[a[x]]; }

void solve(){
    sort(queries, queries + q);
    values.push_back(INT_MAX);
    vector<int> res(q, -1);
    for(int i = 0; i < q; ++i){
        const Query& qr = queries[i];
        while(L > qr.l) add(--L);
        while(R < qr.r) add(++R);
        while(L < qr.l) pop(L++);
        while(R > qr.r) pop(R--);

        int val = f(qr.x);
        res[qr.id] = values[val] == qr.x ? freq[val] : 0;
    }

    for(int i = 0; i < q; ++i){
        cout << res[i] << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        values.push_back(a[i]);
    }
    for(int i = 0; i < q; ++i)
        queries[i].input(i);

    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));

    for(int i = 0; i < n; ++i)
        a[i] = f(a[i]);

    solve();

    return 0;
}
