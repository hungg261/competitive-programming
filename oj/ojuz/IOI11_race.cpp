/******************************************************************************
Link: https://oj.uz/problem/view/IOI11_race
Code: IOI11_race
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-09-15.43.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "race.h"
#else
int best_path(int N, int K, int H[][2], int L[]);

#define MAX_N 500000

static int _N, _K;
static int _H[MAX_N][2];
static int _L[MAX_N];
//static int solution;

inline
void my_assert(int e) {if (!e) abort();}

void read_input()
{
  int i;
  my_assert(2==scanf("%d %d",&_N,&_K));
  for(i=0; i<_N-1; i++)
    my_assert(3==scanf("%d %d %d",&_H[i][0],&_H[i][1],&_L[i]));
//  my_assert(1==scanf("%d",&solution));
}

int main()
{

//freopen("in.txt","r",stdin);
  int ans;
  read_input();
  ans = best_path(_N,_K,_H,_L);
  cout << ans << "\n";
//  if(ans==solution)
//    printf("Correct.\n");
//  else
//    printf("Incorrect. Returned %d, Expected %d.\n",ans,solution);

  return 0;
}

#endif // __________

int n, k;
struct EdgeTo{
    int v, w;
};
vector<vector<EdgeTo>> adj;
vector<int> sz, removed;

void compute(int u, int prv){
    sz[u] = 1;
    for(const EdgeTo& e: adj[u]){
        if(e.v == prv || removed[e.v]) continue;

        compute(e.v, u);
        sz[u] += sz[e.v];
    }
}

int find_centroid(int u, int prv, int root){
    for(const EdgeTo& e: adj[u]){
        if(e.v == prv || removed[e.v]) continue;
        if(sz[e.v] > sz[root] / 2){
            return find_centroid(e.v, u, root);
        }
    }
    return u;
}

vector<int> freq;
void getDepth(int u, int prv, int len, int sum, vector<pair<int, int>>& d){
    if(sum > k) return;
    d.push_back({sum, len});

    for(const EdgeTo& e: adj[u]){
        if(e.v == prv || removed[e.v]) continue;
        getDepth(e.v, u, len + 1, sum + e.w, d);
    }
}

int decompose(int u){
    compute(u, -1);
    int centroid = find_centroid(u, -1, u);

    removed[centroid] = true;

    int res = INT_MAX / 2;
    freq[0] = 0;
    int maxDepth = 0;
    for(EdgeTo& e: adj[centroid]){
        if(removed[e.v]) continue;

        vector<pair<int, int>> depths;
        getDepth(e.v, centroid, 1, e.w, depths);

        for(const pair<int, int>& p: depths){
            int d, len; tie(d, len) = p;
            res = min(res, len + freq[k - d]);
        }
        for(const pair<int, int>& p: depths){
            int d, len; tie(d, len) = p;
            freq[d] = min(freq[d], len);
            maxDepth = max(maxDepth, d);
        }
    }
    for(int val = 0; val <= maxDepth; ++val) freq[val] = INT_MAX / 2;

    for(EdgeTo& e: adj[centroid]){
        if(removed[e.v]) continue;
        res = min(res, decompose(e.v));
    }
    return res;
}

int best_path(int N, int K, int H[][2], int L[]){
    n = N; k = K;
    adj.resize(n); sz.resize(n); removed.resize(n);
    freq.resize(k + 1, INT_MAX / 2);
    for(int i = 0; i < n - 1; ++i){
        adj[H[i][0]].push_back({H[i][1], L[i]});
        adj[H[i][1]].push_back({H[i][0], L[i]});
    }

    int res = decompose(0);
    return (res == INT_MAX / 2 ? -1 : res);
}
