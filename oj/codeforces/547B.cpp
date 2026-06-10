/******************************************************************************
Link: https://codeforces.com/contest/547/problem/B
Code: 547B
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-27-22.27.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int nodes[MAXN * 4 + 5];

void apply(int id, int lz){
    nodes[id] = max(nodes[id], lz);
}

void push(int id){
    apply(id << 1, nodes[id]);
    apply(id << 1 | 1, nodes[id]);
}

void update(int id, int l, int r, int u, int v, int x){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(id, x);
        return;
    }

    push(id);

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, x);
    update(id << 1 | 1, mid + 1, r, u, v, x);
}

int get(int id, int l, int r, int idx){
    if(r < idx || idx < l) return 0;
    if(l == r) return nodes[id];

    push(id);

    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, idx),
               get(id << 1 | 1, mid + 1, r, idx));
}

int n;
int arr[MAXN + 5];

int L[MAXN + 5], R[MAXN + 5];

void compute(){
    vector<int> sta;
    for(int i = 1; i <= n; ++i){
        while(!sta.empty() && arr[sta.back()] >= arr[i]) sta.pop_back();
        L[i] = sta.empty() ? 0 : sta.back();

        sta.push_back(i);
    }

    sta.clear();

    for(int i = n; i >= 1; --i){
        while(!sta.empty() && arr[sta.back()] >= arr[i]) sta.pop_back();
        R[i] = sta.empty() ? n + 1 : sta.back();

        sta.push_back(i);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    compute();

    for(int i = 1; i <= n; ++i){
        int l = L[i] + 1, r = R[i] - 1;
        update(1, 1, n, 1, r - l + 1, arr[i]);
    }

    for(int x = 1; x <= n; ++x){
        cout << get(1, 1, n, x) << " ";
    }

    return 0;
}
