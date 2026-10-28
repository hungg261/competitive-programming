/******************************************************************************
Link: https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/C
Code: edu_2_5_2_279653C
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-28-18.54.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
const int MASK = (1 << 30) - 1;

int n, m;

struct SegTree{
    int tree[MAXN * 4 + 5];
    int lazy[MAXN * 4 + 5];

    void push(int id){
        if(lazy[id]){
            tree[id << 1] |= lazy[id];
            lazy[id << 1] |= lazy[id];
            tree[id << 1 | 1] |= lazy[id];
            lazy[id << 1 | 1] |= lazy[id];
            lazy[id] = 0;
        }
    }

    void update(int id, int l, int r, int u, int v, int val){
        if(v < l || r < u || (tree[id] & val) == val) return;
        if(u <= l && r <= v){
            tree[id] |= val;
            lazy[id] |= val;
            return;
        }
        push(id);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        tree[id] = tree[id << 1] & tree[id << 1 | 1];
    }

    int get(int id, int l, int r, int u, int v){
        if(v < l || r < u) return MASK;
        if(u <= l && r <= v) return tree[id];
        push(id);
        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) & get(id << 1 | 1, mid + 1, r, u, v);
    }
} st;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    while(m--){
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1){
            int v;
            cin >> v;
            st.update(1, 0, n - 1, l, r - 1, v);
        }
        else{
            cout << st.get(1, 0, n - 1, l, r - 1) << "\n";
        }
    }

    return 0;
}
