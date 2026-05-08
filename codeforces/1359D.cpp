/******************************************************************************
Link: https://codeforces.com/contest/1359/problem/D
Code: 1359D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-08-07.19.53
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, a[MAXN + 5], pre[MAXN + 5];

int nodes[MAXN * 4 + 5][2];
void build(int id, int l, int r){
    if(l == r){
        nodes[id][0] = nodes[id][1] = pre[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    nodes[id][0] = min(nodes[id << 1][0], nodes[id << 1 | 1][0]);
    nodes[id][1] = max(nodes[id << 1][1], nodes[id << 1 | 1][1]);
}

int get_min(int id, int l, int r, int u, int v){
    if(v < l || r < u) return INT_MAX;
    if(u <= l && r <= v) return nodes[id][0];

    int mid = (l + r) >> 1;
    return min(get_min(id << 1, l, mid, u, v), get_min(id << 1 | 1, mid + 1, r, u, v));
}

int get_max(int id, int l, int r, int u, int v){
    if(v < l || r < u) return INT_MIN;
    if(u <= l && r <= v) return nodes[id][1];

    int mid = (l + r) >> 1;
    return max(get_max(id << 1, l, mid, u, v), get_max(id << 1 | 1, mid + 1, r, u, v));
}

int L[MAXN + 5], R[MAXN + 5];
void compute(){
    vector<int> sta;
    for(int i = 1; i <= n; ++i){
        while(!sta.empty() && a[sta.back()] <= a[i]) sta.pop_back();
        L[i] = sta.empty() ? 0 : sta.back();
        sta.push_back(i);
    }

    sta.clear();

    for(int i = n; i >= 1; --i){
        while(!sta.empty() && a[sta.back()] <= a[i]) sta.pop_back();
        R[i] = sta.empty() ? n + 1 : sta.back();
        sta.push_back(i);
    }
}

void solve(){
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int res = get_max(1, 0, n, i, R[i] - 1) - get_min(1, 0, n, L[i], i - 1) - a[i];
        ans = max(ans, res);
    }

    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    compute();
    build(1, 0, n);

    solve();

    return 0;
}
