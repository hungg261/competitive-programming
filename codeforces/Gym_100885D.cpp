/******************************************************************************
Link: https://codeforces.com/gym/100885/problem/D
Code: Gym_100885D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-19-09.33.27
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
int n, m;
int a[MAX + 5], b[MAX + 5];

int nodes[MAX * 4 + 5];
void build(int id, int l, int r){
    if(l == r){
        nodes[id] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = min(nodes[id << 1], nodes[id << 1 | 1]);
}

int get(int id, int l, int r, int x){
    if(l > r || x < nodes[id]) return x;
    if(l == r){
        return x % nodes[id];
    }

    int mid = (l + r) >> 1;

    x = get(id << 1, l, mid, x);
    x = get(id << 1 | 1, mid + 1, r, x);
    return x;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("rem.in","r",stdin);
    freopen("rem.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    cin >> m;
    for(int i = 1; i <= m; ++i) cin >> b[i];

    build(1, 1, n);
    for(int i = 1; i <= m; ++i){
        int res = get(1, 1, n, b[i]);
        cout << res << ' ';
    }

    return 0;
}
