/******************************************************************************
Link: https://judge.yosupo.jp/problem/range_set_range_composite
Code: range_set_range_composite
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-14-09.14.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5;
const int MOD = 998'244'353;

int powmod(int a, int b, int m = MOD){
    int res = 1 % m;
    a %= m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

int inv(int b, int m = MOD){ return powmod(b, m - 2, m); }

int n, q;

struct Node{
    int a, b;
    int lza, lzb;

    Node(int _a = 1, int _b = 0, int _lza = -1, int _lzb = -1):
        a(_a % MOD), b(_b % MOD), lza(_lza), lzb(_lzb){}

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

void apply(int id, int l, int r, int a, int b){
    int len = r - l + 1;

    if(a == 1) nodes[id] = Node(1, b * len % MOD);
    else nodes[id] = Node(powmod(a, len), b * (powmod(a, len) - 1) % MOD * inv(a - 1) % MOD);

    nodes[id].lza = a; nodes[id].lzb = b;
}

void push(int id, int l, int r){
    int a = nodes[id].lza, b = nodes[id].lzb;
    if(a == -1 && b == -1) return;

    int mid = (l + r) >> 1;
    apply(id << 1, l, mid, a, b);
    apply(id << 1 | 1, mid + 1, r, a, b);

    nodes[id].lza = -1; nodes[id].lzb = -1;
}

void update(int u, int v, Node nw, int id = 1, int l = 0, int r = n - 1){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(id, l, r, nw.a, nw.b);
        return;
    }

    push(id, l, r);

    int mid = (l + r) >> 1;
    update(u, v, nw, id << 1, l, mid);
    update(u, v, nw, id << 1 | 1, mid + 1, r);
    nodes[id] = nodes[id << 1 | 1] + nodes[id << 1];
}

Node get(int u, int v, int id = 1, int l = 0, int r = n - 1){
    if(v < l || r < u) return Node();
    if(u <= l && r <= v) return nodes[id];

    push(id, l, r);

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

        update(i, i, Node(a, b));
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 0){
            int l, r, c, d;
            cin >> l >> r >> c >> d;

            update(l, r - 1, Node(c, d));
        }
        else if(type == 1){
            int l, r, x;
            cin >> l >> r >> x;

            cout << get(l, r - 1).eval(x) << "\n";
        }
    }

    return 0;
}

