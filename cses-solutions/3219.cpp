/******************************************************************************
Link: https://cses.fi/problemset/task/3219
Code: 3219
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-18-11.19.12
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int arr[MAXN + 5];
int n, k;

struct Pair{
    int value, idx;

    bool operator < (const Pair& other) const{
        return value < other.value || (value == other.value && idx < other.idx);
    }
};

Pair nodes[MAXN * 2 + 5];
void build(){
    for(int i = 0; i < n; ++i){
        nodes[i + n] = {0, i};
    }

    for(int id = n - 1; id > 0; --id){
        nodes[id] = min(nodes[id << 1], nodes[id << 1 | 1]);
    }
}

void update(int id, int delta){
    id += n;
    nodes[id].value += delta;
    nodes[id].idx = id - n;

    while(id > 1){
        id >>= 1;
        nodes[id] = min(nodes[id << 1], nodes[id << 1 | 1]);
    }
}

int get(int l, int r){
    l += n;
    r += n;
    ++r;

    Pair res = {INT_MAX, n + 5};
    while(l < r){
        if(l & 1) res = min(res, nodes[l++]);
        if(r & 1) res = min(res, nodes[--r]);
        l >>= 1; r >>= 1;
    }

    return res.idx;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    build();
    for(int i = 1; i <= n; ++i){
        if(arr[i] < k) update(arr[i], 1);
        if(i >= k){
            int res = get(0, n - 1);
            cout << res << ' ';

            if(arr[i - k + 1] < k) update(arr[i - k + 1], -1);
        }
    }

    return 0;
}
