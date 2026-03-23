#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, a[MAXN + 5];
long long nodes[MAXN * 4 + 5];

void build(int id, int l, int r){
    if(l == r){
        nodes[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    nodes[id] = nodes[id * 2] + nodes[id * 2 + 1];
}

void update(int id, int l, int r, int idx, int value){
    if(idx < l || r < idx){
        return;
    }
    if(l == r){
        nodes[id] = value;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, idx, value);
    update(id * 2 + 1, mid + 1, r, idx, value);

    nodes[id] = nodes[id * 2] + nodes[id * 2 + 1];
}

long long query(int id, int l, int r, int u, int v){
    if(u <= l && r <= v){
        return nodes[id];
    }
    if(r < u || v < l) return 0;

    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

void build(){
    build(1, 1, n);
}

void update(int k, int u){
    update(1, 1, n, k, u);
}

long long query(int l, int r){
    return query(1, 1, n, l, r);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build();

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int k, u;
            cin >> k >> u;

            update(k, u);
        }
        else{
            int u, v;
            cin >> u >> v;

            cout << query(u, v) << '\n';
        }
    }

    return 0;
}
