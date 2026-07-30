/******************************************************************************
Link: https://oj.uz/problem/view/IOI11_crocodile
Code: IOI11_crocodile
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-26-19.01.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 1e6;

#ifndef __________
#include "crocodile.h"
#else
int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]);

int _R[MAXM + 5][2], _L[MAXM + 5], _P[MAXN + 5], _N, _M, _K;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> _N >> _M >> _K;
    for(int i = 0; i < _M; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        _R[i][0] = a;
        _R[i][1] = b;
        _L[i] = c;
    }
    for(int i = 0; i < _K; ++i)
        cin >> _P[i];


    cout << travel_plan(_N, _M, _R, _L, _K, _P) << "\n";

    return 0;
}
#endif

#define int long long
const int INF = 1e18;

struct Pair{
    int v[2] = {INF, INF};

    bool push(int x){
        int old = v[1];
        if(x < v[0]){
            v[1] = v[0];
            v[0] = x;
        }
        else if(x < v[1]) v[1] = x;

        return v[1] < old;
    }

    int size(){ return (v[0] != INF) + (v[1] != INF); }

    int operator [] (int idx) const { return v[idx]; }
    int& operator [] (int idx){ return v[idx]; }
};

struct EdgeTo{ int v, w; };
vector<EdgeTo> adj[MAXN + 5];
Pair w[MAXN + 5];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct State{
    int u;
    long long cost;

    bool operator > (const State& other) const {
        return cost > other.cost;
    }
};

int32_t travel_plan(int32_t N, int32_t M, int32_t R[][2], int32_t L[], int32_t K, int32_t P[]){
    for(int i = 0; i < M; ++i){
        adj[R[i][0]].push_back({R[i][1], L[i]});
        adj[R[i][1]].push_back({R[i][0], L[i]});
    }
    for(int u = 0; u < N; ++u)
        shuffle(begin(adj[u]), end(adj[u]), rng);

    priority_queue<State, vector<State>, greater<State>> que;
    for(int i = 0; i < K; ++i){
        que.push({P[i], 0});
        w[P[i]][0] = w[P[i]][1] = 0;
    }

    while(!que.empty()){
        State cur = que.top(); que.pop();
        if(cur.cost != w[cur.u][1]) continue;

        for(const EdgeTo& e: adj[cur.u]){
            int newCost = cur.cost + e.w;
            if(w[e.v].push(newCost)){
                que.push({e.v, w[e.v][1]});
            }
        }
    }

    return w[0][1] < 0 || w[0][1] == INF ? -1 : w[0][1];
}
