#include<bits/stdc++.h>
#define int long long
using namespace std;

const int PCNT = 35;
int primes[PCNT] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
    101, 103, 107, 109, 113, 127, 131, 137, 139, 149
};

const int MAXN = 5e4;
int powmod(int a, int b, int mod){
    int res = 1;
    a %= mod;

    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

struct Node{
    int cnt[PCNT];
    int lazy[PCNT];

    Node(){
        clear();
    }

    void clear(){
        memset(cnt, 0, sizeof cnt);
        memset(lazy, 0, sizeof lazy);
    }

    Node operator + (const Node& other){
        Node res;
        for(int i = 0; i < PCNT; ++i){
            res.cnt[i] = cnt[i] + other.cnt[i];
        }

        return res;
    }

    int calc(int mod){
        int res = 1;
        for(int i = 0; i < PCNT; ++i)
            res = res * powmod(primes[i], cnt[i], mod) % mod;
        return res;
    }

    void debug(){
        for(int i = 0; i < PCNT; ++i){
            cerr << cnt[i] << ' ';
        }
        cerr << '\n';
    }
};

Node nodes[MAXN * 4 + 5];

void down(int id, int l, int r){
    int mid = (l + r) >> 1;

    for(int c = 0; c < PCNT; ++c){
        int& lz = nodes[id].lazy[c];

        nodes[id << 1].cnt[c] += lz * (mid - l + 1);
        nodes[id << 1].lazy[c] += lz;

        nodes[id << 1 | 1].cnt[c] += lz * (r - mid);
        nodes[id << 1 | 1].lazy[c] += lz;

        lz = 0;
    }
}

void update(int id, int l, int r, int u, int v, int X, int mul){
    if(r < u || v < l) return;
    if(u <= l && r <= v){
        int temp = X;
        for(int c = 0; c < PCNT; ++c){
            int p = primes[c], co = 0;
            while(temp % p == 0){
                ++co;
                temp /= p;
            }

            nodes[id].cnt[c] += mul * co * (r - l + 1);
            nodes[id].lazy[c] += mul * co;
        }
        return;
    }

    down(id, l, r);

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, X, mul);
    update(id << 1 | 1, mid + 1, r, u, v, X, mul);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

Node get(int id, int l, int r, int u, int v){
    if(r < u || v < l) return Node();
    if(u <= l && r <= v) return nodes[id];

    down(id, l, r);

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

int n, q;

void update(int l, int r, int X, int mul){
    if(l > r){
        update(1, 1, n, l, n, X, mul);
        update(1, 1, n, 1, r, X, mul);
    }
    else{
        update(1, 1, n, l, r, X, mul);
    }
}

int get(int l, int r, int M){
    if(l > r){
        Node res = get(1, 1, n, l, n) + get(1, 1, n, 1, r);
        return res.calc(M);
    }
    else{
        return get(1, 1, n, l, r).calc(M);
    }
}

void reset(int id, int l, int r){
    nodes[id].clear();
    if(l == r) return;

    int mid = (l + r) >> 1;
    reset(id << 1, l, mid);
    reset(id << 1 | 1, mid + 1, r);
}

void dfs(int id, int l, int r){
    cerr << id << " " << l << " " << r << ": "; nodes[id].debug();
    if(l == r) return;

    down(id, l, r);

    int mid = (l + r) >> 1;
    dfs(id << 1, l, mid);
    dfs(id << 1 | 1, mid + 1, r);
}

void query(){
    cin >> n >> q;

    reset(1, 1, n);
    while(q--){
        int type, l, r, V;
        cin >> type >> l >> r >> V;

        if(type == 0){
            cout << get(l, r, V) << '\n';
        }
        else if(type == 1){
            update(l, r, V, 1);
        }
        else{
            update(l, r, V, -1);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        query();
    }

    return 0;
}
