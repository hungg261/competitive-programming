#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5;
int n;
vector<int> a[N + 7];
int p[N + 7];

struct Segtree{
    vector<int> st;
    Segtree(int sz) : st(4 * sz + 7, 0) {}
    void update(int id, int l, int r, int u, int v){
        if(u < l || r < u) return;
        if(l == r){
            st[id] = v;
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v);
        update(id << 1 | 1, mid + 1, r, u, v);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }
    int get(int id, int l, int r, int u, int v){
        if(v < l || r < u) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }

    void clear(){
        fill(begin(st), end(st), 0);
    }
};
Segtree st1(67);
int res = 0;
void dfs(int u, int par){
    if(u != 0) st1.update(1, 0, n, u, 1);
//    if(u % 10000 == 0) cerr << "??" << u / 10000 << "\n";
    if(u != 0) res += st1.get(1, 0, n, 0, u - 1);
    for(int v : a[u]){
        if(v == par) continue;
        p[v] = u;
        dfs(v, u);
    }
    if(u != 0) st1.update(1, 0, n, u, 0);
}

vector<int> sta; int contrib = 0;
void dfs2(int u, int par){
    int sz = (int)a[u].size();
    if(!sta.empty()){
        if(p[u] != p[sta.back()] && sta.back() > u){
//            cerr << "connect: " << u << " " << sta.back() << endl;
            ++contrib;
//            cerr << "add: " << u << endl;
        }
    }
    for(int i = 0; i < sz; ++i){
        int v = a[u][i];
        if(v == par) continue;

        int nxt = -1;
        if (i + 1 < sz) {
            if (a[u][i + 1] != par) nxt = a[u][i + 1];
            else if (i + 2 < sz) nxt = a[u][i + 2];
        }
        if (nxt != -1) sta.push_back(nxt);
        dfs2(v, u);
        if (nxt != -1) sta.pop_back();
    }

    if(u != 0 && sz == 1) ++contrib;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("input.txt", "r", stdin);

    int t = 1;
    cin >> t;

    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i){
            a[i].clear();
        }
        st1 = Segtree(n + 5);
        contrib = 0;
        sta.clear();
        res = 0;

        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for(int i = 0; i < n; i++){
            sort(a[i].begin(), a[i].end());
        }
        dfs(0, 0);
//        cerr << "ok\n";
        dfs2(0, 0);
//        cerr << "C: " << contrib << endl;
        cout << res + contrib - 1 << "\n";
    }
    return 0;
}
