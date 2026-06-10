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

const int MAXN = 2e5, MAXQ = 2e5;
int n, q, arr[MAXN + 5], mark[MAXN + 5];
vector<int> P[MAXN + 5];
vector<pair<int, int>> Q[MAXQ + 5];

void solve(){
    FenwickTree fwt(n);
    vector<int> res(q + 1);

    for(int i = n; i >= 1; --i){
        for(int r: P[i]){
            fwt.update(r, 1);
        }

        for(const pair<int, int>& p: Q[i]){
            int r = p.first, idx = p.second;
            res[idx] = fwt.get(i, r);
        }
    }

    for(int i = 1; i <= q; ++i){
        cout << res[i] << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        mark[arr[i]] = i;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = arr[i]; j <= n; j += arr[i]){
            int l = i, r = mark[j];
            if(l > r) swap(l, r);

            P[l].push_back(r);
        }
    }

    for(int i = 1; i <= q; ++i){
        int l, r;
        cin >> l >> r;

        Q[l].emplace_back(r, i);
    }

    solve();

    return 0;
}
