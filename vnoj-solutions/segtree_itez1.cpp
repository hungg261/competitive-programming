#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int nodes[MAXN * 2 + 5];
int arr[MAXN + 5], n;

void build(){
    for(int i = 0; i < n; ++i){
        nodes[i + n] = arr[i + 1];
    }

    for(int id = n - 1; id > 0; --id){
        nodes[id] = max(nodes[id << 1], nodes[id << 1 | 1]);
    }
}

void update(int id, int val){
    --id;
    id += n;
    nodes[id] = val;

    while(id > 0){
        id >>= 1;
        nodes[id] = max(nodes[id << 1], nodes[id << 1 | 1]);
    }
}

int get(int l, int r){
    --l;
    l += n; r += n;

    int res = -1e9;
    while(l < r){
        if(l & 1) res = max(res, nodes[l++]);
        if(r & 1) res = max(res, nodes[--r]);
        l >>= 1; r >>= 1;
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    build();

    int q;
    cin >> q;

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int x, y;
            cin >> x >> y;

            update(x, y);
        }
        else{
            int l, r;
            cin >> l >> r;

            cout << get(l, r) << '\n';
        }
    }

    return 0;
}
