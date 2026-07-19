/******************************************************************************
Link: https://oj.uz/problem/view/IOI20_supertrees
Code: IOI20_supertrees
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-18-17.14.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "supertrees.h"
#else
int construct(std::vector<std::vector<int>> p);
void build(std::vector<std::vector<int>> b);

static int n;
static std::vector<std::vector<int>> p;
static std::vector<std::vector<int>> b;
static bool called = false;

static void check(bool cond, std::string message) {
    if (!cond) {
        printf("%s\n", message.c_str());
        fclose(stdout);
        exit(0);
    }
}

void build(std::vector<std::vector<int>> _b) {
    check(!called, "build is called more than once");
    called = true;
    check((int)_b.size() == n, "Invalid number of rows in b");
    for (int i = 0; i < n; i++) {
        check((int)_b[i].size() == n, "Invalid number of columns in b");
    }
    b = _b;
}

int main() {
    assert(scanf("%d", &n) == 1);

    p.resize(n);
    for (int i = 0; i < n; i++) {
        p[i].resize(n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            assert(scanf("%d", &p[i][j]) == 1);
        }
    }
    fclose(stdin);

    int possible = construct(p);

    check(possible == 0 || possible == 1, "Invalid return value of construct");
    if (possible == 1) {
        check(called, "construct returned 1 without calling build");
    } else {
        check(!called, "construct called build but returned 0");
    }

    printf("%d\n", possible);
    if (possible == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j) {
                    printf(" ");
                }
                printf("%d", b[i][j]);
            }
            printf("\n");
        }
    }
    fclose(stdout);
}
#endif // __________

#pragma GCC diagnostic ignored "-Wshadow"

struct DSU{
    int n;
    vector<int> par, sz;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
    }

    void init(){
        for(int u = 0; u <= n; ++u)
            create(u);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
    }

    int find(int v){
        return par[v] == v ? v : par[v] = find(par[v]);
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];

            return true;
        }

        return false;
    }
};

int construct(std::vector<std::vector<int>> p){
    int n = p.size();
    DSU cycle(n), tree(n);
    cycle.init(); tree.init();

    for(int i = 0; i < n; ++i){
        if(p[i][i] != 1) return 0;
        for(int j = 0; j < n; ++j){
            if(i == j) continue;
            else if(p[i][j] != p[j][i]) return 0;

            if(p[i][j] == 3) return 0;
            else if(p[i][j] == 1){
                tree.unite(i, j);
            }
        }
    }

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(p[i][j] == 2 && tree.same(i, j)) return 0;
            if(p[i][j] == 2 && !tree.same(i, j)){
                cycle.unite(tree.find(i), tree.find(j));
            }
        }
    }

    for(int u = 0; u < n; ++u){
        int root = tree.find(u);
        if(root != u) adj[root][u] = 1;
    }

    map<int, vector<int>> last;
    for(int u = 0; u < n; ++u){
        int root = cycle.find(u);
        last[root].push_back(u);
    }

    for(const pair<int, vector<int>>& p: last){
        int sz = p.second.size();
        if(sz == 1) continue;
        else if(sz == 2) return 0;
        for(int i = 0; i < sz; ++i){
            adj[p.second[i]][p.second[(i + 1) % sz]] = 1;
        }
    }

    for(int u = 0; u < n; ++u)
        for(int v = 0; v < n; ++v)
            adj[u][v] = max(adj[u][v], adj[v][u]);

    for(int u = 0; u < n; ++u){
        for(int v = 0; v < n; ++v){
            if(u == v) continue;
            if(p[u][v] == 2 && tree.same(u, v)) return 0;
            if(p[u][v] == 1 && cycle.same(u, v)) return 0;
            if(p[u][v] == 0 && (tree.same(u, v) || cycle.same(u, v))) return 0;
        }
    }

    build(adj);

    return 1;
}
