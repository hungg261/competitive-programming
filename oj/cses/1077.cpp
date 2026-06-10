/******************************************************************************
Link: https://cses.fi/problemset/task/1077
Code: 1077
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-12-11.37.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int nodes[2][MAXN * 4 + 5];

void add(int o, int id, int l, int r, int idx, int val){
    if(r < idx || idx < l) return;
    if(l == r){
        nodes[o][id] += val;
        return;
    }

    int mid = (l + r) >> 1;
    if(idx <= mid) add(o, id << 1, l, mid, idx, val);
    else add(o, id << 1 | 1, mid + 1, r, idx, val);

    nodes[o][id] = nodes[o][id << 1] + nodes[o][id << 1 | 1];
}

int sum(int o, int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return nodes[o][id];

    int mid = (l + r) >> 1;
    return sum(o, id << 1, l, mid, u, v) + sum(o, id << 1 | 1, mid + 1, r, u, v);
}

int order(int o, int id, int l, int r, int S){
    if(l == r) return l;

    int mid = (l + r) >> 1;
    if(nodes[o][id << 1] < S)
        return order(o, id << 1 | 1, mid + 1, r, S - nodes[o][id << 1]);
    else return order(o, id << 1, l, mid, S);
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

        add(0, 1, 1, n, arr[i], 1);
        add(1, 1, 1, n, arr[i], temp[arr[i]]);
        if(i > k){
            add(0, 1, 1, n, arr[i - k], -1);
            add(1, 1, 1, n, arr[i - k], -temp[arr[i - k]]);
        }

        if(i >= k){
            int mid = order(0, 1, 1, n, (k + 1) / 2);

            int smaller_c = sum(0, 1, 1, n, 1, mid - 1), larger_c = sum(0, 1, 1, n, mid + 1, n);
            int smaller = sum(1, 1, 1, n, 1, mid - 1), larger = sum(1, 1, 1, n, mid + 1, n);

            int res = (temp[mid] * smaller_c - smaller) + (larger - temp[mid] * larger_c);
            cout << res << " ";
        }
    }

    return 0;
}
