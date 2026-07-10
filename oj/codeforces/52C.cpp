/******************************************************************************
Link: https://codeforces.com/problemset/problem/52/C
Code: 52C
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-10-21.05.22
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int n, a[MAXN];
int nodes[MAXN * 4 + 5], lazy[MAXN * 4 + 5];

void build(int id = 1, int l = 0, int r = n - 1){
    if(l == r){
        nodes[id] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = min(nodes[id << 1], nodes[id << 1 | 1]);
}

void apply(int id, int lz){
    nodes[id] += lz;
    lazy[id] += lz;
}

void push(int id){
    int &lz = lazy[id];

    apply(id << 1, lz);
    apply(id << 1 | 1, lz);

    lz = 0;
}

void add(int u, int v, int val, int id = 1, int l = 0, int r = n - 1){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(id, val);
        return;
    }

    push(id);

    int mid = (l + r) >> 1;
    add(u, v, val, id << 1, l, mid);
    add(u, v, val, id << 1 | 1, mid + 1, r);
    nodes[id] = min(nodes[id << 1], nodes[id << 1 | 1]);
}

int get(int u, int v, int id = 1, int l = 0, int r = n - 1){
    if(v < l || r < u) return LLONG_MAX;
    if(u <= l && r <= v) return nodes[id];

    push(id);

    int mid = (l + r) >> 1;
    return min(get(u, v, id << 1, l, mid),
               get(u, v, id << 1 | 1, mid + 1, r));
}

void update(int l, int r, int val){
    if(l > r){
        add(l, n - 1, val);
        add(0, r, val);
        return;
    }

    add(l, r, val);
}

int ask(int l, int r){
    if(l > r) return min(get(l, n - 1), get(0, r));
    return get(l, r);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    build();

    int q;
    cin >> q;

    cin.ignore();
    while(q--){
        string line;
        getline(cin, line);

        stringstream ss(line);

        vector<int> tokens;
        int value;
        while(ss >> value) tokens.push_back(value);

        if(tokens.size() == 3ull){
            update(tokens[0], tokens[1], tokens[2]);
        }
        else if(tokens.size() == 2ull){
            cout << ask(tokens[0], tokens[1]) << "\n";
        }
        else abort();
    }

    return 0;
}
