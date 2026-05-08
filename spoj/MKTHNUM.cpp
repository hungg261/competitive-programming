/******************************************************************************
Link: https://www.spoj.com/problems/MKTHNUM/
Code: MKTHNUM
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-08-08.44.46
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

const int MAXN = 1e5, MAXQ = 5000;
int n, m;
pair<int, int> a[MAXN + 5];

vector<int> candidates[MAXN + 5];
int l[MAXQ + 5], r[MAXQ + 5], k[MAXQ + 5];
int L[MAXQ + 5], R[MAXQ + 5];

void solve(){
    while(true){
        bool changed = false;
        for(int q = 1; q <= m; ++q){
            if(L[q] >= R[q]) continue;

            int mid = (L[q] + R[q]) >> 1;
            candidates[mid].push_back(q);
            changed = true;
        }
        if(!changed) break;

        FenwickTree mark(n);
        for(int i = 1; i <= n; ++i){
            mark.update(a[i].second, 1);

            for(int q: candidates[i]){
                if(mark.get(l[q], r[q]) >= k[q])
                    R[q] = i;
                else L[q] = i + 1;
            }
            candidates[i].clear();
        }
    }

    for(int i = 1; i <= m; ++i){
        cout << a[L[i]].first << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i = 1; i <= m; ++i){
        cin >> l[i] >> r[i] >> k[i];
        L[i] = 1, R[i] = n;
    }

    sort(a + 1, a + n + 1);

    solve();

    return 0;
}
