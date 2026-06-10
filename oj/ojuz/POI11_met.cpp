/******************************************************************************
Link: https://oj.uz/problem/view/POI11_met
Code: POI11_met
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-05-21.05.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<long long> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    long long get(int idx){
        if(idx <= 0) return 0;

        long long res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    long long get(int l, int r){ return get(r) - get(l - 1); }
};

const int MAXN = 3e5, MAXM = 3e5, MAXQ = 3e5;
int n, m, q;
int o[MAXM + 5], p[MAXN + 5];
vector<int> groups[MAXN + 5];

FenwickTree fwt;
void add(int l, int r, int x){
    fwt.update(l, x);
    fwt.update(r + 1, -x);
}

struct Query{
    int l, r, x;

    void use(){
        if(l > r){
            add(1, r, x);
            add(l, m, x);
            return;
        }

        add(l, r, x);
    }
};
vector<Query> queries;

int l[MAXQ + 5], r[MAXQ + 5];
vector<int> candidates[MAXN + 5];

void solve(){
    while(true){
        bool changed = false;
        for(int i = 1; i <= n; ++i){
            if(l[i] >= r[i]) continue;

            candidates[(l[i] + r[i]) / 2].push_back(i);
            changed = true;
        }
        if(!changed) break;

        for(int i = 1; i <= q; ++i){
            queries[i].use();

            for(int g: candidates[i]){
                long long sum = 0;
                for(int idx: groups[g]){
                    sum += fwt.get(idx);
                    if(sum >= p[g]) break;
                }

                if(sum >= p[g]) r[g] = i;
                else l[g] = i + 1;
            }

            candidates[i].clear();
        }

        fwt = FenwickTree(m + 1);
    }

    for(int i = 1; i <= n; ++i){
        if(l[i] <= q) cout << l[i] << "\n";
        else cout << "NIE\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    fwt = FenwickTree(m + 1);
    for(int i = 1; i <= m; ++i){
        cin >> o[i];
        groups[o[i]].push_back(i);
    }
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }

    cin >> q;

    for(int i = 1; i <= n; ++i)
        l[i] = 1, r[i] = q + 1;

    queries.resize(q + 1);
    for(int i = 1; i <= q; ++i){
        int l, r, x;
        cin >> l >> r >> x;

        queries[i] = {l, r, x};
    }

    solve();

    return 0;
}
