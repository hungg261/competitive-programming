/******************************************************************************
Link: https://cses.fi/problemset/task/1736
Code: 1736
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-20-21.58.52
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
struct Node{
    int delta_i = 0, delta_l = 0, lazy_i = 0, lazy_l = 0;

    Node operator + (const Node& other){
        Node res;
        res.delta_i = delta_i + other.delta_i;
        res.delta_l = delta_l + other.delta_l;
        return res;
    }

    void debug(){
        cerr << delta_i << ' ' << delta_l << '\n';
    }

    int value(){
        return delta_i + delta_l;
    }
} nodes[MAXN * 4 + 5];

inline int progsum(int l, int r){ return (l + r) * (r - l + 1) / 2; }

void push(int id, int l, int r){
    int &lzi = nodes[id].lazy_i, &lzl = nodes[id].lazy_l;
    int mid = (l + r) >> 1;

    nodes[id << 1].delta_i += lzi * progsum(l, mid);
    nodes[id << 1].delta_l -= lzl * (mid - l + 1);
    nodes[id << 1].lazy_i += lzi;
    nodes[id << 1].lazy_l += lzl;

    nodes[id << 1 | 1].delta_i += lzi * progsum(mid + 1, r);
    nodes[id << 1 | 1].delta_l -= lzl * (r - mid);
    nodes[id << 1 | 1].lazy_i += lzi;
    nodes[id << 1 | 1].lazy_l += lzl;

    lzi = 0;
    lzl = 0;
}

void update(int id, int l, int r, int u, int v){
    if(r < u || v < l) return;
    if(u <= l && r <= v){
        nodes[id].delta_i += progsum(l, r);
        nodes[id].delta_l -= (u - 1) * (r - l + 1);

        nodes[id].lazy_i++;
        nodes[id].lazy_l += u - 1;
        return;
    }

    push(id, l, r);

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v);
    update(id << 1 | 1, mid + 1, r, u, v);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

Node get(int id, int l, int r, int u, int v){
    if(r < u || v < l) return Node();
    if(u <= l && r <= v) return nodes[id];

    push(id, l, r);

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

int n, q;
int arr[MAXN + 5], pre[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1736.INP","r",stdin);
    //freopen("1736.OUT","w",stdout);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }

    while(q--){
        int type, a, b;
        cin >> type >> a >> b;

        if(type == 1){
            update(1, 1, n, a, b);
        }
        else{
            cout << get(1, 1, n, a, b).value() + (pre[b] - pre[a - 1]) << '\n';
        }
    }

    return 0;
}
