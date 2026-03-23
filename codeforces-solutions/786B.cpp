/******************************************************************************
Link: https://codeforces.com/problemset/problem/786/B
Code: 786B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-04-08.01.09
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 1e5;
int n, q, s;

struct Node{
    vector<pair<Node*, int>> edges;
    Node *l, *r;
    int dist = INF;

    Node(): l(nullptr), r(nullptr){}
    Node(Node *_l, Node *_r): l(_l), r(_r){}

    void set(Node *node){
        if(!l) l = node;
        else if(!r) r = node;
    }

    bool operator < (const Node& other) const{
        return dist < other.dist;
    }
};

Node *leaf[MAXN + 5];

Node *build1(int l, int r){
    if(l == r){
        return leaf[l] = new Node();
    }

    int mid = (l + r) >> 1;
    Node *res = new Node();
    res->l = build1(l, mid);
    res->r = build1(mid + 1, r);

    res->edges.emplace_back(res->l, 0);
    res->edges.emplace_back(res->r, 0);

    return res;
}

Node *build2(int l, int r){
    if(l == r){
        return leaf[l];
    }

    int mid = (l + r) >> 1;
    Node *res = new Node();
    res->l = build2(l, mid);
    res->r = build2(mid + 1, r);

    res->l->edges.emplace_back(res, 0);
    res->r->edges.emplace_back(res, 0);

    return res;
}

void add1(Node *node, int l, int r, int u, int x, int y, int w){
    if(y < l || r < x) return;
    if(x <= l && r <= y){
        leaf[u]->edges.emplace_back(node, w);
        return;
    }

    int mid = (l + r) >> 1;
    add1(node->l, l, mid, u, x, y, w);
    add1(node->r, mid + 1, r, u, x, y, w);
}

void add2(Node *node, int l, int r, int v, int x, int y, int w){
    if(y < l || r < x) return;
    if(x <= l && r <= y){
        node->edges.emplace_back(leaf[v], w);
        return;
    }

    int mid = (l + r) >> 1;
    add2(node->l, l, mid, v, x, y, w);
    add2(node->r, mid + 1, r, v, x, y, w);
}

void dijkstra(int s){
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<>> pq;
    leaf[s]->dist = 0;
    pq.push({0, leaf[s]});

    while(!pq.empty()){
        int cost; Node* u;
        tie(cost, u) = pq.top();
        pq.pop();

        if(cost != u->dist) continue;

        for(const pair<Node*, int>& e: u->edges){
            Node *v; int w;
            tie(v, w) = e;

            int newCost = cost + w;
            if(newCost < v->dist){
                v->dist = newCost;
                pq.push({newCost, v});
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << (leaf[i]->dist == INF ? -1 : leaf[i]->dist) << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q >> s;

    Node *uproot = build1(1, n);
    Node *downroot = build2(1, n);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int u, v, w;
            cin >> u >> v >> w;

            add1(uproot, 1, n, u, v, v, w);
        }
        else if(type == 2){
            int u, l, r, w;
            cin >> u >> l >> r >> w;

            add1(uproot, 1, n, u, l, r, w);
        }
        else if(type == 3){
            int v, l, r, w;
            cin >> v >> l >> r >> w;

            add2(downroot, 1, n, v, l, r, w);
        }
    }

    dijkstra(s);

    return 0;
}
