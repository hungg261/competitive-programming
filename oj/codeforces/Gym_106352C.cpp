/******************************************************************************
Link: https://codeforces.com/gym/106352/problem/C
Code: Gym_106352C
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-01-21.38.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXVAL = 1e7, LIM = MAXVAL + 1000;
int spf[LIM + 5];
int n, q, a[MAXN + 5], ans[MAXN + 5];

vector<pair<int,int>> queries[MAXN + 5];
vector<int> primes;
vector<int> nodes;

void compute(){
    for(int i = 2; i * i <= LIM; ++i){
        if(!spf[i]) for(int j = i * i; j <= LIM; j += i)
            if(!spf[j]) spf[j] = i;
    }

    for(int i = 2; i <= LIM; ++i){
        if(!spf[i]){
            spf[i] = -primes.size();
            primes.push_back(i);
        }
    }
}

void update(int id, int l, int r, int pos, int val){
    if(l == r){
        nodes[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(id << 1, l, mid, pos, val);
    else update(id << 1 | 1, mid + 1, r, pos, val);
    nodes[id] = min(nodes[id << 1], nodes[id << 1 | 1]);
}

int findFirst(int id, int l, int r, int need){
    if(nodes[id] >= need) return -1;
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(nodes[id << 1] < need) return findFirst(id << 1, l, mid, need);
    return findFirst(id << 1 | 1, mid + 1, r, need);
}

void solve(){
    int P = primes.size();
    nodes.assign(4 * P + 5, 0);

    for(int r = 1; r <= n; ++r){
        int num = a[r];
        while(num > 1){
            int p = spf[num];
            if(p <= 0) p = num;
            int idx = -spf[p];

            update(1, 0, P - 1, idx, r);

            while(num % p == 0)
                num /= p;
        }

        for(const pair<int, int> &qr: queries[r]){
            int l, id; tie(l, id) = qr;
            int idx = findFirst(1, 0, P - 1, l);
            ans[id] = primes[idx];
        }
    }

    for(int i = 1; i <= q; ++i) cout << ans[i] << "\n";
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
        queries[r].push_back({l, i});
    }

    compute();
    solve();

    return 0;
}
