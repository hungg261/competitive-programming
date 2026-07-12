/******************************************************************************
Link: https://oj.uz/problem/view/IOI13_dreaming
Code: IOI13_dreaming
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-12-15.33.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "dreaming.h"
#else
int travelTime(int N, int M, int L, int A[], int B[], int T[]);

#define MAX_N 100000

static int A[MAX_N];
static int B[MAX_N];
static int T[MAX_N];

int main() {
	int N, M, L, i;

	fscanf(stdin, "%d%d%d", &N, &M, &L);
	for (i = 0; i < M; i++)
		fscanf(stdin, "%d%d%d", &A[i], &B[i], &T[i]);

	int answer = travelTime(N, M, L, A, B, T);
	printf("%d\n", answer);

	return 0;
}

#endif // __________

#pragma GCC diagnostic ignored "-Wshadow"

const int MAXN = 1e5, MAXLG = __lg(MAXN) + 1;
int n;
struct EdgeTo{ int v, w; };
vector<EdgeTo> adj[MAXN + 5];

int table[MAXN + 5][MAXLG + 5];

int h[MAXN + 5], g[MAXN + 5];
int head[MAXN + 5];

void dfs(int u, int hd, int prv = -1){
    head[u] = hd;

    for(int j = 1; j <= MAXLG; ++j)
        table[u][j] = table[table[u][j - 1]][j - 1];

    for(const EdgeTo& e: adj[u]){
        if(e.v == prv) continue;

        h[e.v] = h[u] + 1;
        g[e.v] = g[u] + e.w;
        table[e.v][0] = u;

        dfs(e.v, hd, u);
    }
}

int lift(int u, int steps){
    for(int b = MAXLG; b >= 0; --b)
        if(steps >> b & 1) u = table[u][b];

    return u;
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    v = lift(v, h[v] - h[u]);

    if(u == v) return u;

    for(int b = MAXLG; b >= 0; --b){
        if(table[u][b] != table[v][b]){
            u = table[u][b];
            v = table[v][b];
        }
    }

    return table[u][0];
}

int find_dist(int u, int v, int s[]){
    return s[u] + s[v] - s[find_lca(u, v)] * 2;
}

int getPos(int u, int v, int k){
    int lca = find_lca(u, v);
    if(k <= h[u] - h[lca]) return lift(u, k);

    return lift(v, find_dist(u, v, h) - k);
}

pair<int, int> dfs_farthest(int u, int prv = -1){
    pair<int, int> best = {0, u};
    for(const EdgeTo& e: adj[u]){
        if(e.v == prv) continue;

        pair<int, int> cand = dfs_farthest(e.v, u);
        if(cand.first + e.w > best.first)
            best = {cand.first + e.w, cand.second};
    }

    return best;
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    n = N;
    for(int i = 0; i < M; ++i){
        ++A[i]; ++B[i];
        adj[A[i]].push_back({B[i], T[i]});
        adj[B[i]].push_back({A[i], T[i]});
    }

    for(int u = 1; u <= n; ++u){
        if(!g[u]) dfs(u, u, -1);
    }

    vector<pair<int, int>> cands;
    for(int u = 1; u <= n; ++u){
        if(head[u] != u) continue;

        int a = dfs_farthest(u).second;
        int b = dfs_farthest(a).second;

        if(h[a] > h[b]) swap(a, b);

        int D = find_dist(a, b, g);
        int l = 0, r = find_dist(a, b, h);
        pair<int, int> res = {INT_MAX, -1};
        while(l <= r){
            int mid = (l + r) >> 1;
            int o = getPos(b, a, mid);

            int L = find_dist(o, a, g);
            int R = D - L;

            res = min(res, {max(L, R), o});
            if(L < R) r = mid - 1;
            else if(L > R) l = mid + 1;
            else break;
        }

        cands.push_back(res);
    }

    sort(begin(cands), end(cands), greater<pair<int, int>>());

    int st = cands[0].second;
    for(int i = 1; i < (int)cands.size(); ++i){
        int en = cands[i].second;

        adj[st].push_back({en, L});
        adj[en].push_back({st, L});
    }

    return dfs_farthest(dfs_farthest(1, -1).second, -1).first;
}
