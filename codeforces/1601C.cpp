/******************************************************************************
Link: https://codeforces.com/problemset/problem/1601/C
Code: 1601C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-30-09.10.22
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
    int getTo(int i){ return get(i); }
    int getFrom(int i){ return get(n) - get(i - 1); }
};

const int MAXN = 1e6, MAXM = 1e6;
int n, m, a[MAXN + 5], b[MAXM + 5];

int L[2], R[2];
FenwickTree fwt[2];

void add(int o, int i){ fwt[o].update(a[i], 1); }
void pop(int o, int i){ fwt[o].update(a[i], -1); }
void query(int o, int l, int r){
    while(L[o] > l) add(o, --L[o]);
    while(R[o] < r) add(o, ++R[o]);
    while(L[o] < l) pop(o, L[o]++);
    while(R[o] > r) pop(o, R[o]--);
}

long long compute(int l, int r, int optL, int optR){
    if(l > r) return 0;

    int mid = (l + r) >> 1;
    query(0, 1, optL);
    query(1, optL + 1, n);
    long long curInv = fwt[0].getFrom(b[mid] + 1) + fwt[1].getTo(b[mid] - 1);

    pair<long long, int> best = {curInv, optL};
    for(int i = optL + 1; i <= optR; ++i){
        if(a[i] < b[mid]) --curInv;
        if(a[i] > b[mid]) ++curInv;

        best = min(best, {curInv, i});
    }

    int opt = best.second;
    return best.first + compute(l, mid - 1, optL, opt) + compute(mid + 1, r, opt, optR);
}

void solve(){
    cin >> n >> m;

    vector<int> values;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        values.push_back(a[i]);
    }
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
        values.push_back(b[i]);
    }
    sort(b + 1, b + m + 1);

    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));
    FenwickTree mark(values.size() + 3);

    long long inv = 0;
    for(int i = n; i >= 1; --i){
        a[i] = lower_bound(begin(values), end(values), a[i]) - begin(values) + 1;
        mark.update(a[i], 1);
        inv += mark.get(a[i] - 1);
    }
    for(int i = 1; i <= m; ++i) b[i] = lower_bound(begin(values), end(values), b[i]) - begin(values) + 1;

    fwt[0] = FenwickTree(values.size() + 3);
    fwt[1] = FenwickTree(values.size() + 3);
    L[0] = L[1] = 1, R[0] = R[1] = 0;

    cout << inv + compute(1, m, 0, n) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
