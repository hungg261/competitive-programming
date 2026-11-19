/******************************************************************************
Link: https://qoj.ac/problem/13281
Code: 13281
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-19-10.35.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

template<typename T = int>
struct SegmentTree{
    struct Node{
        T value;
        T lazy;

        Node(): value(0), lazy(0){}
        Node(T _value, T _lazy = 0): value(_value), lazy(_lazy){}

        static Node Identity(){
            return Node(numeric_limits<T>::lowest(), 0);
        }

        Node merge(const Node& other){
            return Node(max(value, other.value), 0);
        }
    };

    int n;
    vector<Node> nodes;

    SegmentTree() = default;
    SegmentTree(int sz): n(sz){
        nodes.resize(n * 4 + 1);
    }

    void apply(int id, T val){
        nodes[id].value += val;
        nodes[id].lazy += val;
    }

    void push(int id){
        if(nodes[id].lazy == 0) return;
        apply(id << 1, nodes[id].lazy);
        apply(id << 1 | 1, nodes[id].lazy);
        nodes[id].lazy = 0;
    }

    void build(int id, int l, int r, const vector<T>& arr){
        if(l == r){
            nodes[id] = Node(arr[l], 0);
            return;
        }

        int mid = (l + r) >> 1;
        build(id << 1, l, mid, arr);
        build(id << 1 | 1, mid + 1, r, arr);
        nodes[id] = nodes[id << 1].merge(nodes[id << 1 | 1]);
    }

    void update(int id, int l, int r, int u, int v, T val){
        if(r < u || v < l) return;
        if(u <= l && r <= v){
            apply(id, val);
            return;
        }

        push(id);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        nodes[id] = nodes[id << 1].merge(nodes[id << 1 | 1]);
    }

    Node get(int id, int l, int r, int u, int v){
        if(r < u || v < l) return Node::Identity();
        if(u <= l && r <= v) return nodes[id];

        push(id);
        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v).merge(get(id << 1 | 1, mid + 1, r, u, v));
    }

    void build(const vector<T>& arr){ build(1, 1, n, arr); }
    void update(int u, int v, T val){ update(1, 1, n, u, v, val); }
    Node get(int u, int v){ return get(1, 1, n, u, v); }
};

const int MAXN = 3e5;
int n, q, s[MAXN + 5];
vector<int> adj[MAXN + 5];

namespace HLD{

int head[MAXN + 5], pos[MAXN + 5], Timer = 0;
int sz[MAXN + 5], h[MAXN + 5], par[MAXN + 5];

void dfs(int u = 1, int prv = -1){
    sz[u] = 1;
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void hld(int u = 1, int hd = 1, int prv = -1){
    head[u] = hd;
    pos[u] = ++Timer;

    int nxt = -1;
    for(int v: adj[u]){
        if(v == prv) continue;
        if(nxt == -1 || sz[v] > sz[nxt]) nxt = v;
    }
    if(nxt != -1) hld(nxt, hd, u);

    for(int v: adj[u]){
        if(v == prv || v == nxt) continue;
        hld(v, v, u);
    }
}

}

SegmentTree<int> st;
void update_path(int u){
    while(u != 0){
        st.update(HLD::pos[HLD::head[u]], HLD::pos[u], 1);
        u = HLD::par[HLD::head[u]];
    }
}

int query(int u) {
    vector<pair<int, int>> seg;
    while(u != 0){
        seg.emplace_back(HLD::pos[HLD::head[u]], HLD::pos[u]);
        u = HLD::par[HLD::head[u]];
    }
    reverse(begin(seg), end(seg));

    int res = 0;
    for(int i = 1; i < (int)seg.size(); ++i){
        if(seg[i - 1].second + 1 <= seg[i].first - 1){
            res = max(res, st.get(seg[i - 1].second + 1, seg[i].first - 1).value);
        }
    }
    if(seg.back().second + 1 <= n){
        res = max(res, st.get(seg.back().second + 1, n).value);
    }
    return res;
}

namespace Org{

int order[MAXN + 5], tin[MAXN + 5], Timer = 0;

void compute(){
    priority_queue<tuple<int, int, int>> pq;
    pq.push({s[1], 1, -1});

    while(!pq.empty()){
        const auto p = pq.top();
        pq.pop();

        int u = get<1>(p), prv = get<2>(p);

        tin[u] = ++Timer;
        order[Timer] = u;

        for(int v: adj[u]){
            if(v == prv) continue;
            pq.push({s[v], v, u});
        }
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 2; i <= n; ++i){
        int p; cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
    }

    HLD::dfs();
    HLD::hld();
    Org::compute();
    st = SegmentTree<int>(n);

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        int u = Org::order[i];
        ans[u] = (i - 1) - query(u);
        update_path(u);
    }

    while(q--){
        int u;
        cin >> u;

        cout << ans[u] << " ";
    }

    return 0;
}
