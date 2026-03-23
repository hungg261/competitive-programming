/******************************************************************************
Link: https://codeforces.com/contest/1567/problem/E
Code: 1567E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-23-21.06.53
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int arr[MAXN + 5];

struct Node{
    int maxPre, maxSuf, Cnt;
    int L, R;

    Node(int filled = 0, int l = 0, int r = 0): maxPre(filled), maxSuf(filled), Cnt(filled), L(l), R(r){}

    Node operator + (const Node& other) const{
        Node res;

        res.L = L;
        res.R = other.R;

        res.maxPre = maxPre;
        res.maxSuf = other.maxSuf;
        res.Cnt = Cnt + other.Cnt;


        if(arr[R] <= arr[other.L]){
            if(maxPre == R - L + 1) res.maxPre += other.maxPre;
            if(other.maxSuf == other.R - other.L + 1) res.maxSuf += maxSuf;

            res.Cnt -= maxSuf * (maxSuf + 1) / 2;
            res.Cnt -= other.maxPre * (other.maxPre + 1) / 2;

            int newLength = maxSuf + other.maxPre;
            res.Cnt += newLength * (newLength + 1) / 2;
        }

        return res;
    }
};

Node nodes[MAXN * 4 + 5];

void build(int id, int l, int r){
    if(l == r){
        cin >> arr[l];
        nodes[id] = Node(1, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

void update(int id, int l, int r, int idx, int val){
    if(r < idx || idx < l) return;
    if(l == r){
        arr[l] = val;
        nodes[id] = Node(1, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, idx, val);
    update(id << 1 | 1, mid + 1, r, idx, val);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

Node get(int id, int l, int r, int u, int v){
    if(v < l || r < u) throw runtime_error("weirdo");
    if(u <= l && r <= v) return nodes[id];

    int mid = (l + r) >> 1;

    if(r < u || v < mid + 1) return get(id << 1, l, mid, u, v);
    if(mid < u || v < l) return get(id << 1 | 1, mid + 1, r, u, v);

    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;

    build(1, 1, n);

    while(q--){
        int type; cin >> type;

        if(type == 1){
            int x, y;
            cin >> x >> y;

            update(1, 1, n, x, y);
        }
        else{
            int l, r;
            cin >> l >> r;

            cout << get(1, 1, n, l, r).Cnt << '\n';
        }
    }

    return 0;
}
