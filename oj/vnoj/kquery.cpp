/******************************************************************************
Link: https://oj.vnoi.info/problem/kquery
Code: kquery
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-20-23.52.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 30000;
vector<int> nodes[MAXN * 4 + 5];
int arr[MAXN + 5], n;

void build(int id, int l, int r){
    if(l == r){
        nodes[id].push_back(arr[l]);
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    nodes[id].resize(r - l + 1);
    merge(begin(nodes[id << 1]), end(nodes[id << 1]),
          begin(nodes[id << 1 | 1]), end(nodes[id << 1 | 1]),
          begin(nodes[id]));
}

int get(int id, int l, int r, int u, int v, int k){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v){
        return end(nodes[id]) - upper_bound(begin(nodes[id]), end(nodes[id]), k);
    }

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v, k) + get(id << 1 | 1, mid + 1, r, u, v, k);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    build(1, 1, n);

    int q;
    cin >> q;

    while(q--){
        int l, r, k;
        cin >> l >> r >> k;

        cout << get(1, 1, n, l, r, k) << '\n';
    }

    return 0;
}
