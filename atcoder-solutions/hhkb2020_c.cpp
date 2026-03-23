/******************************************************************************
Link: https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_c
Code: hhkb2020_c
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-22-18.31.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXVAL = 2e5;
int nodes[MAXVAL * 4 + 5];

void add(int id, int l, int r, int idx, int val){
    if(r < idx || idx < l) return;
    if(l == r){
        nodes[id] += val;
        return;
    }

    int mid = (l + r) >> 1;
    add(id << 1, l, mid, idx, val);
    add(id << 1 | 1, mid + 1, r, idx, val);
    nodes[id] = min(nodes[id << 1], nodes[id << 1 | 1]);
}

int find_mex(int id, int l, int r){
    if(l > r || nodes[id] > 0) return -1;
    if(l == r){
        return nodes[id] == 0 ? l : -1;
    }

    int mid = (l + r) >> 1;

    int mex;
    mex = find_mex(id << 1, l, mid);
    if(mex != -1) return mex;

    mex = find_mex(id << 1 | 1, mid + 1, r);
    if(mex != -1) return mex;

    return -1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;

        add(1, 0, MAXVAL, cur, 1);
        cout << find_mex(1, 0, MAXVAL) << '\n';
    }


    return 0;
}
