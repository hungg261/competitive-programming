/******************************************************************************
Link: https://cses.fi/problemset/task/1735
Code: 1735
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-21-20.15.45
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
int n, q, arr[MAXN + 5];
int nodes[MAXN * 4 + 5], lazyInc[MAXN * 4 + 5], lazySet[MAXN * 4 + 5], pending[MAXN * 4 + 5];

void build(int id, int l, int r){
    if(l == r){
        nodes[id] = arr[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

void down(int id, int l, int r){
    int &lzS = lazySet[id], &lzI = lazyInc[id];
    int mid = (l + r) >> 1;

    if(lzS != 0){
        nodes[id << 1] = lzS * (mid - l + 1);
        lazySet[id << 1] = lzS;
        lazyInc[id << 1] = 0;

        nodes[id << 1 | 1] = lzS * (r - mid);
        lazySet[id << 1 | 1] = lzS;
        lazyInc[id << 1 | 1] = 0;
    }

    nodes[id << 1] += lzI * (mid - l + 1);
    lazyInc[id << 1] += lzI;

    nodes[id << 1 | 1] += lzI * (r - mid);
    lazyInc[id << 1 | 1] += lzI;

    lzS = 0;
    lzI = 0;
}

void Increase(int id, int l, int r, int u, int v, int x){
    if(r < u || v < l) return;
    if(u <= l && r <= v){
        nodes[id] += x * (r - l + 1);
        lazyInc[id] += x;

        return;
    }

    down(id, l, r);

    int mid = (l + r) >> 1;
    Increase(id << 1, l, mid, u, v, x);
    Increase(id << 1 | 1, mid + 1, r, u, v, x);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

void Set(int id, int l, int r, int u, int v, int x){
    if(r < u || v < l) return;
    if(u <= l && r <= v){
        nodes[id] = x * (r - l + 1);
        lazySet[id] = x;
        lazyInc[id] = 0;

        return;
    }

    down(id, l, r);

    int mid = (l + r) >> 1;
    Set(id << 1, l, mid, u, v, x);
    Set(id << 1 | 1, mid + 1, r, u, v, x);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

int get(int id, int l, int r, int u, int v){
    if(r < u || v < l) return 0;
    if(u <= l && r <= v) return nodes[id];

    down(id, l, r);

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1735.INP","r",stdin);
    //freopen("1735.OUT","w",stdout);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    build(1, 1, n);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int a, b, x;
            cin >> a >> b >> x;

            Increase(1, 1, n, a, b, x);
        }
        else if(type == 2){
            int a, b, x;
            cin >> a >> b >> x;

            Set(1, 1, n, a, b, x);
        }
        else{
            int a, b;
            cin >> a >> b;

            cout << get(1, 1, n, a, b) << '\n';
        }
    }

    return 0;
}
