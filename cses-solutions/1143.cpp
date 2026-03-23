/******************************************************************************
Link: https://cses.fi/problemset/task/1143
Code: 1143
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-22-12.52.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int nodes[MAXN * 4 + 5];

void add(int id, int l, int r, int idx, int val){
    if(r < idx || idx < l) return;
    if(l == r){
        nodes[id] += val;
        return;
    }

    int mid = (l + r) >> 1;
    add(id << 1, l, mid, idx, val);
    add(id << 1 | 1, mid + 1, r, idx, val);
    nodes[id] = max(nodes[id << 1], nodes[id << 1 | 1]);
}

int walk(int id, int l, int r, int k){
    if(l > r || nodes[id] < k) return 0;
    if(l == r){
        return nodes[id] >= k ? l : 0;
    }

    int mid = (l + r) >> 1;

    int idx;
    idx = walk(id << 1, l, mid, k);
    if(idx > 0) return idx;

    idx = walk(id << 1 | 1, mid + 1, r, k);
    if(idx > 0) return idx;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        add(1, 1, n, i, cur);
    }

    for(int i = 1; i <= m; ++i){
        int r; cin >> r;

        int idx = walk(1, 1, n, r);
        cout << idx << ' ';

        if(idx > 0) add(1, 1, n, idx, -r);
    }

    return 0;
}
