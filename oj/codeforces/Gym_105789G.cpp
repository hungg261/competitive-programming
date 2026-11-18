/******************************************************************************
Link: https://codeforces.com/gym/105789/problem/G
Code: Gym_105789G
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-15-19.00.21
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 200000;
const int INF = 1e18;

int n;
char tp[MAXN + 5];
int LL[MAXN + 5], PP[MAXN + 5];

vector<int> coords;

struct SegTree{
    int sz;
    vector<int> mx, cnt, lazy, wt;

    void init(vector<int>& weights){
        sz = weights.size();
        mx.assign(4 * sz, 0);
        cnt.assign(4 * sz, 0);
        lazy.assign(4 * sz, 0);
        wt = weights;
        build(1, 0, sz - 1);
    }

    void build(int node, int l, int r){
        if(l == r){
            cnt[node] = wt[l];
            return;
        }
        int m = (l + r) >> 1;
        build(node << 1, l, m);
        build(node << 1 | 1, m + 1, r);
        pull(node);
    }

    void pull(int node){
        mx[node] = max(mx[node << 1], mx[node << 1 | 1]);
        cnt[node] = 0;
        if(mx[node << 1] == mx[node]) cnt[node] += cnt[node << 1];
        if(mx[node << 1 | 1] == mx[node]) cnt[node] += cnt[node << 1 | 1];
    }

    void apply(int node, int v){
        mx[node] += v;
        lazy[node] += v;
    }

    void push(int node){
        if(lazy[node]){
            apply(node << 1, lazy[node]);
            apply(node << 1 | 1, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int v){
        if(ql > r || qr < l) return;
        if(ql <= l && r <= qr){
            apply(node, v);
            return;
        }
        push(node);
        int m = (l + r) >> 1;
        update(node << 1, l, m, ql, qr, v);
        update(node << 1 | 1, m + 1, r, ql, qr, v);
        pull(node);
    }

    pair<int, int> query(int node, int l, int r, int ql, int qr){
        if(ql > r || qr < l) return {-INF, 0};
        if(ql <= l && r <= qr) return {mx[node], cnt[node]};
        push(node);
        int m = (l + r) >> 1;
        auto left = query(node << 1, l, m, ql, qr);
        auto right = query(node << 1 | 1, m + 1, r, ql, qr);

        int M = max(left.first, right.first);
        int C = 0;
        if(left.first == M) C += left.second;
        if(right.first == M) C += right.second;

        return {M, C};
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> tp[i] >> LL[i] >> PP[i];
        coords.push_back(PP[i]);
        if(tp[i] == '|') coords.push_back(PP[i] + 1);
        else coords.push_back(PP[i] + LL[i]);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    int sz = coords.size() - 1;
    vector<int> weights(sz);
    for(int i = 0; i < sz; ++i){
        weights[i] = coords[i + 1] - coords[i];
    }

    SegTree st;
    st.init(weights);

    string ans;
    for(int i = 0; i < n; ++i){
        int pi = lower_bound(coords.begin(), coords.end(), PP[i]) - coords.begin();

        if(tp[i] == '|'){
            st.update(1, 0, sz - 1, pi, pi, LL[i]);
            ans.push_back('S');
        }
        else{
            int pj = lower_bound(coords.begin(), coords.end(), PP[i] + LL[i]) - coords.begin();
            auto res = st.query(1, 0, sz - 1, pi, pj - 1);
            if(res.second == LL[i]){
                st.update(1, 0, sz - 1, pi, pj - 1, 1);
                ans.push_back('S');
            }
            else{
                ans.push_back('U');
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
