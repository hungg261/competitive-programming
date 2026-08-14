/******************************************************************************
Link: https://judge.yosupo.jp/problem/point_set_range_composite
Code: point_set_range_composite
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-12-17.07.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5;
const int MOD = 998'244'353;
int n, q;

struct Node{
    int a, b;

    Node(int _a = 1, int _b = 0): a(_a % MOD), b(_b % MOD){}

    int eval(int x){ return ((a * x % MOD + b) % MOD + MOD) % MOD; }

    friend istream& operator >> (istream& is, Node& nd){
        return is >> nd.a >> nd.b;
    }
    friend ostream& operator << (ostream& os, const Node& nd){
        return os << nd.a << " " << nd.b;
    }

    Node operator + (const Node& other) const {
        return Node{a * other.a % MOD, (a * other.b + b) % MOD};
    }
} nodes[MAXN * 4 + 5];

void update(int idx, Node nw, int id = 1, int l = 0, int r = n - 1){
    if(idx < l || r < idx) return;
    if(l == r){
        nodes[id] = nw;
        return;
    }

    int mid = (l + r) >> 1;
    update(idx, nw, id << 1, l, mid);
    update(idx, nw, id << 1 | 1, mid + 1, r);
    nodes[id] = nodes[id << 1 | 1] + nodes[id << 1];
}

Node get(int u, int v, int id = 1, int l = 0, int r = n - 1){
    if(v < l || r < u) return Node();
    if(u <= l && r <= v) return nodes[id];

    int mid = (l + r) >> 1;
    return get(u, v, id << 1 | 1, mid + 1, r)
        + get(u, v, id << 1, l, mid);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;

        update(i, Node(a, b));
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 0){
            int p, c, d;
            cin >> p >> c >> d;

            update(p, Node(c, d));
        }
        else if(type == 1){
            int l, r, x;
            cin >> l >> r >> x;

            cout << get(l, r - 1).eval(x) << "\n";
        }
    }

    return 0;
}
