/******************************************************************************
Link: https://codeforces.com/contest/617/problem/E
Code: 617E
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-27-14.22.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXQ = 1e5, MAXVAL = 1e6, MAXBLOCK = 300;

int n, q, k;
int P[MAXN + 5];

namespace Mo{

struct Query{
    int l, r, id;

    void input(int i){
        id = i;
        cin >> l >> r;
    }

    bool operator < (const Query& other) const {
        int b1 = l / MAXBLOCK, b2 = other.l / MAXBLOCK;
        if(b1 != b2) return b1 < b2;
        return (b1 & 1) ? r < other.r : r > other.r;
    }
};

int L = 1, R = 0;
int cnt[MAXVAL * 2 + 5];
long long res = 0;

void add(int i){
    res += cnt[k ^ P[i]];
    cnt[P[i]]++;
}

void pop(int i){
    --cnt[P[i]];
    res -= cnt[k ^ P[i]];
}

void move(int l, int r){
    while(L > l) add(--L);
    while(R < r) add(++R);
    while(L < l) pop(L++);
    while(R > r) pop(R--);
}

}
Mo::Query queries[MAXQ + 5];

namespace Solve{

void solve(){
    sort(queries + 1, queries + q + 1);

    vector<long long> res(q + 1, -1);
    for(int i = 1; i <= q; ++i){
        Mo::move(queries[i].l, queries[i].r);
        res[queries[i].id] = Mo::res;
    }

    for(int i = 1; i <= q; ++i){
        cout << res[i] << "\n";
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q >> k;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        P[i] = P[i - 1] ^ cur;
    }

    for(int i = 1; i <= q; ++i){
        queries[i].input(i);
        queries[i].l--;
    }

    Solve::solve();

    return 0;
}
