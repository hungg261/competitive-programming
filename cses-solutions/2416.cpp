/******************************************************************************
Link: https://cses.fi/problemset/task/2416
Code: 2416
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-19-19.16.49
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
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

    int get(int l, int r){ return l > r ? 0 : get(r) - get(l - 1); }

    void assign(int idx, int val){
        update(idx, val - get(idx, idx));
    }
};

struct State{
    int r, idx;
};

const int MAXN = 2e5;
int n, q, arr[MAXN + 5], pre[MAXN + 5];
vector<State> queries[MAXN + 5];

int Search(const vector<int>& sta, int target){
    int l = 0, r = (int)sta.size() - 1, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(target >= sta[mid]){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}

void solve(){
    vector<int> res(q + 1);
    vector<int> sta;
    FenwickTree fwt(n + 1);
    for(int i = n; i >= 1; --i){
        while(!sta.empty() && arr[sta.back()] <= arr[i]){
            fwt.assign(sta.back() - 1, 0);
            sta.pop_back();
        }
        int nxt = sta.empty() ? n + 1 : sta.back();
        fwt.assign(nxt - 1, arr[i] * (nxt - i));

        sta.push_back(i);

        for(const State& qr: queries[i]){
            int r = qr.r;

            int pos = Search(sta, r);
            res[qr.idx] = arr[sta[pos]] * (r - sta[pos] + 1);
            res[qr.idx] += fwt.get(sta[pos] - 1);
            res[qr.idx] -= pre[r] - pre[i - 1];
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
        pre[i] = pre[i - 1] + arr[i];
    }

    for(int i = 1; i <= q; ++i){
        int l, r;
        cin >> l >> r;

        queries[l].push_back({r, i});
    }

    solve();

    return 0;
}
