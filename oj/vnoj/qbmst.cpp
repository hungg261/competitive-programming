/******************************************************************************
Link: https://oj.vnoi.info/problem/qbmst
Code: qbmst
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-14.41.40
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    DSU dsu(n);

    long long mstWeight = 0;
    int used = 0;

    for (const Edge &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mstWeight += e.w;
            used++;
            if (used == n - 1) break;
        }
    }

    cout << mstWeight << '\n';

    return 0;
}
