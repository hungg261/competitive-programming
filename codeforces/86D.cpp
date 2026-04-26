/******************************************************************************
Link: https://codeforces.com/contest/86/problem/D
Code: 86D
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-26-08.44.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, BLOCKSIZE = 530;
const int MAXVAL = 1e6, MAXQ = 2e5;

struct Query{
    int l, r, idx;

    bool operator < (const Query& other) const {
        int b1 = l / BLOCKSIZE, b2 = other.l / BLOCKSIZE;

        if(b1 != b2) return b1 < b2;
        return (b1 & 1) ? r > other.r : r < other.r;
    }
};

int freq[MAXVAL + 5];
long long cur = 0;
void add(int x){
    cur -= 1LL * freq[x] * freq[x] * x;
    ++freq[x];
    cur += 1LL * freq[x] * freq[x] * x;
}

void pop(int x){
    cur -= 1LL * freq[x] * freq[x] * x;
    --freq[x];
    cur += 1LL * freq[x] * freq[x] * x;
}

vector<Query> queries;
int a[MAXN + 5], n, q;
long long res[MAXQ + 5];
void mo(){
    sort(begin(queries), end(queries));
    int L = 1, R = 0;

    for(const Query& q: queries){
        while(L > q.l) add(a[--L]);
        while(R < q.r) add(a[++R]);
        while(L < q.l) pop(a[L++]);
        while(R > q.r) pop(a[R--]);

        res[q.idx] = cur;
    }

    for(int i = 1; i <= q; ++i)
        cout << res[i] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    for(int i = 1; i <= q; ++i){
        int l, r;
        cin >> l >> r;

        queries.push_back({l, r, i});
    }

    mo();

    return 0;
}
