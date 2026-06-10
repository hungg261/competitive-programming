/******************************************************************************
Link: https://codeforces.com/problemset/problem/896/C
Code: 896C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-16-11.41.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct ODT{
    struct Node{
        int l, r;
        mutable long long val;

        Node(int _l, int _r, int _v): l(_l), r(_r), val(_v){}
        Node(int _idx, int _v): l(_idx), r(_idx), val(_v){}

        int powmod(int b, int m) const {
            int res = 1 % m;
            int a = val % m;
            while(b > 0){
                if(b & 1) res = 1LL * res * a % m;
                a = 1LL * a * a % m;
                b >>= 1;
            }
            return res;
        }

        bool operator < (const Node& other) const {
            return l < other.l;
        }
    };

    set<Node> S;

    ODT() = default;

    void init(int l, int r, int val){ S.insert({l, r, val}); }
    void init(int i, int val){ S.insert({i, val}); }

    set<Node>::iterator split(int pos){
        auto it = S.lower_bound({pos, -1, -1});
        if(it != S.end() && it->l == pos) return it;

        --it;
        if(it->r < pos) return S.end();

        int l = it->l, r = it->r, v = it->val;
        S.erase(it);
        S.insert({l, pos - 1, v});
        return S.insert({pos, r, v}).first;
    }

    void assign(int l, int r, int val){
        auto itR = split(r + 1);
        auto itL = split(l);

        S.erase(itL, itR);
        S.insert({l, r, val});
    }

    void add(int l, int r, int x){
        auto itR = split(r + 1);
        auto itL = split(l);

        for(auto it = itL; it != itR; ++it){
            it->val += x;
        }
    }

    long long kth(int l, int r, int k){
        auto itR = split(r + 1);
        auto itL = split(l);

        multiset<pair<long long, int>> sub;
        for(auto it = itL; it != itR; ++it){
            sub.insert({it->val, it->r - it->l + 1});
        }

        for(const pair<long long, int>& p: sub){
            k -= p.second;
            if(k <= 0) return p.first;

        }

        return -1;
    }

    int query(int l, int r, int x, int y){
        auto itR = split(r + 1);
        auto itL = split(l);

        int res = 0;
        for(auto it = itL; it != itR; ++it){
            res = (res + 1LL * (it->r - it->l + 1) * it->powmod(x, y) % y) % y;
        }
        return res;
    }

    void debug(){
        for(const Node& node: S){
            cerr << node.l << " " << node.r << " " << node.val << "\n";
        }
    }
};

const int MAXN = 1e5;
int n, m, seed, vmax;

int rnd(){
    int ret = seed;
    seed = (1LL * seed * 7 + 13) % 1000000007;
    return ret;
}

void solve(){
    ODT odt;
    for(int i = 1; i <= n; ++i){
        int val = rnd() % vmax + 1;
        odt.init(i, val);
    }

    for(int i = 1; i <= m; ++i){
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        int x, y;

        if (l > r) swap(l, r);

        if (op == 3) x = (rnd() % (r - l + 1)) + 1;
        else x = (rnd() % vmax) + 1;

        if (op == 4) y = (rnd() % vmax) + 1;

        if(op == 1){
            odt.add(l, r, x);
        }
        else if(op == 2){
            odt.assign(l, r, x);
        }
        else if(op == 3){
            cout << odt.kth(l, r, x) << "\n";
        }
        else if(op == 4){
            cout << odt.query(l, r, x, y) << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> seed >> vmax;

    solve();

    return 0;
}
