/******************************************************************************
Link: https://oj.uz/problem/view/IOI13_dreaming
Code: IOI13_dreaming
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-12-17.01.31
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

int h[MAXN + 5], g[MAXN + 5];
int head[MAXN + 5];

void dfs(int u, int hd, int prv = -1){
    head[u] = hd;
    for(const EdgeTo& e: adj[u]){
        if(e.v == prv) continue;

        h[e.v] = h[u] + 1;
        g[e.v] = g[u] + e.w;

        dfs(e.v, hd, u);
    }
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

pair<int, int> dfs_path(int u, int prv, int t, int D, int dist = 0){
    if(u == t) return {dist, t};
    for(const EdgeTo& e: adj[u]){
        if(e.v == prv) continue;

        int newDist = dist + e.w;
        pair<int, int> cand = dfs_path(e.v, u, t, D, newDist);
        if(cand.first != -1){
            return min(cand, {max(newDist, D - newDist), e.v});
        }
    }

    return {-1, -1};
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
        pair<int, int> _temp = dfs_farthest(a);
        int D = _temp.first;
        int b = _temp.second;

        cands.push_back(dfs_path(a, -1, b, D));
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
