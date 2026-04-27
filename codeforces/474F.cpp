/******************************************************************************
Link: https://codeforces.com/contest/474/problem/F
Code: 474F
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-27-18.03.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int arr[MAXN + 5], n;
map<int, vector<int>> pos;

int nodes[MAXN * 4 + 5];

void build(int id, int l, int r){
    if(l == r){
        nodes[id] = arr[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = __gcd(nodes[id << 1], nodes[id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return nodes[id];

    int mid = (l + r) >> 1;
    return __gcd(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }

    build(1, 1, n);

    int q; cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;

        int x = get(1, 1, n, l, r);
        const vector<int>& idx = pos[x];

        int cnt = upper_bound(begin(idx), end(idx), r) - lower_bound(begin(idx), end(idx), l);
        cout << (r - l + 1 - cnt) << "\n";
    }

    return 0;
}
