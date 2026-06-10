/******************************************************************************
Link: https://codeforces.com/problemset/problem/242/E
Code: 242E
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-28-22.26.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
    struct Node{
        int b[2];
        int lazy;

        Node(int b0 = 0, int b1 = 0, int lz = 0): lazy(lz){
            b[0] = b0;
            b[1] = b1;
        }

        void apply(int lz){
            lazy ^= lz;
        }

        int eval(int x = 0) const { return this->b[lazy ^ x]; }

        Node operator + (const Node& other) const {
            int nb0 = eval(0) + other.eval(0),
                nb1 = eval(1) + other.eval(1);

            return Node(nb0, nb1, 0);
        }
    };

    int n;
    vector<Node> nodes;

    SegmentTree(int sz = -1): n(sz){
        if(sz == -1) return;

        nodes.resize(n * 4 + 1);
        build(1, 1, n);
    }

    void build(int id, int l, int r){
        nodes[id].b[0] = r - l + 1;
        if(l == r) return;

        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
    }

    void push(int id){
        int &lz = nodes[id].lazy;

        nodes[id << 1].apply(lz);
        nodes[id << 1 | 1].apply(lz);

        lz = 0;
    }

    void update(int id, int l, int r, int u, int v){
        if(v < l || r < u) return;
        if(u <= l && r <= v){
            nodes[id].apply(1);
            return;
        }

        push(id);

        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v);
        update(id << 1 | 1, mid + 1, r, u, v);
        nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
    }

    int get(int id, int l, int r, int u, int v){
        if(v < l || r < u) return 0;
        if(u <= l && r <= v) return nodes[id].eval(1);

        push(id);

        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }

    void update(int l, int r){ update(1, 1, n, l, r); }
    int get(int l, int r){ return get(1, 1, n, l, r); }
};

const int MAXN = 1e5, MAXVAL = 1e6, MAXLG = __lg(MAXVAL);
int n;
SegmentTree ST[MAXLG + 1];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;

        for(int b = MAXLG; b >= 0; --b){
            ST[b] = SegmentTree(n);

            if(cur >> b & 1)
                ST[b].update(1, 1, n, i, i);
        }
    }

    int m;
    cin >> m;

    while(m--){
        int type;
        cin >> type;

        if(type == 2){
            int l, r, x;
            cin >> l >> r >> x;

            for(int b = MAXLG; b >= 0; --b){
                if(x >> b & 1)
                    ST[b].update(1, 1, n, l, r);
            }
        }
        else{
            int l, r;
            cin >> l >> r;

            long long res = 0;
            for(int b = MAXLG; b >= 0; --b){
                cerr << "q: " << ST[b].get(1, 1, n, l, r) << endl;
                res += ST[b].get(1, 1, n, l, r) * (1LL << b);
            }

            cout << res << "\n";
        }
    }

    return 0;
}
