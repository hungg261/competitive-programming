/******************************************************************************
Link: https://cses.fi/problemset/task/1076
Code: 1076
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-12-10.55.12
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
    if(idx <= mid) add(id << 1, l, mid, idx, val);
    else add(id << 1 | 1, mid + 1, r, idx, val);

    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

int order(int id, int l, int r, int S){
    if(l == r) return l;

    int mid = (l + r) >> 1;
    if(nodes[id << 1] < S)
        return order(id << 1 | 1, mid + 1, r, S - nodes[id << 1]);
    else return order(id << 1, l, mid, S);
}

int a[MAXN + 5], arr[MAXN + 5], temp[MAXN + 5];
int n, k;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        temp[i] = arr[i] = a[i];
    }
    sort(temp + 1, temp + n + 1);

    for(int i = 1; i <= n; ++i){
        arr[i] = lower_bound(temp + 1, temp + n + 1, arr[i]) - temp;

        add(1, 1, n, arr[i], 1);
        if(i > k) add(1, 1, n, arr[i - k], -1);

        if(i >= k)
            cout << temp[order(1, 1, n, (k + 1) / 2)] << " ";
    }

    return 0;
}
