/******************************************************************************
Link: https://oj.uz/problem/view/IOI14_game
Code: IOI14_game
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-23-11.18.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "game.h"
#else
void initialize(int n);
int hasEdge(int u, int v);

int read_int() {
    int x;
    assert(scanf("%d", &x) == 1);
    return x;
}

signed main() {
    int n, u, v;
    n = read_int();
    initialize(n);
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        u = read_int();
        v = read_int();
        printf("%d\n", hasEdge(u, v));
    }
    return 0;
}


#endif // __________

int N;
vector<int> deg;
void initialize(int n) {
    N = n;
    deg.resize(N, 0);
}

int hasEdge(int u, int v) {
    if(u > v) swap(u, v);
    return ++deg[v] == v;
}
