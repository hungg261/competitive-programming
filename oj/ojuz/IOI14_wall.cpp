/******************************************************************************
Link: https://oj.uz/problem/view/IOI14_wall
Code: IOI14_wall
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-15-12.03.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "wall.h"
#else
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]);
signed main()
{
  int n;
  int k;

  int i, j;
  int status = 0;

  status = scanf("%d%d", &n, &k);
  assert(status == 2);

  int* op = (int*)calloc(sizeof(int), k);
  int* left = (int*)calloc(sizeof(int), k);
  int* right = (int*)calloc(sizeof(int), k);
  int* height = (int*)calloc(sizeof(int), k);
  int* finalHeight = (int*)calloc(sizeof(int), n);

  for (i = 0; i < k; i++){
    status = scanf("%d%d%d%d", &op[i], &left[i], &right[i], &height[i]);
    assert(status == 4);
  }

  buildWall(n, k, op, left, right, height, finalHeight);

  for (j = 0; j < n; j++)
    printf("%d\n", finalHeight[j]);

  return 0;
}
#endif // __________

const int MAXN = 2e6;
int N;

struct Node{
    int mn, mx;
    int lz;

    Node operator + (const Node& other) const {
        Node res;
        res.mn = min(mn, other.mn);
        res.mx = max(mx, other.mx);
        res.lz = -1;
        return res;
    }
} nodes[MAXN * 4 + 5];

void build(int id = 1, int l = 0, int r = N - 1){
    if(l == r){
        nodes[id].mn = nodes[id].mx = 0;
        nodes[id].lz = -1;
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

void push(int id){
    if(nodes[id].lz != -1){
        nodes[id << 1].mn = nodes[id << 1].mx = nodes[id].lz;
        nodes[id << 1 | 1].mn = nodes[id << 1 | 1].mx = nodes[id].lz;

        nodes[id << 1].lz = nodes[id].lz;
        nodes[id << 1 | 1].lz = nodes[id].lz;

        nodes[id].lz = -1;
        return;
    }
}

void add(int u, int v, int val, int id = 1, int l = 0, int r = N - 1){
    if(l > r || v < l || r < u) return;
    if(u <= l && r <= v && nodes[id].mx <= val){
        nodes[id].mn = nodes[id].mx = val;
        nodes[id].lz = val;
        return;
    }
    else if(l == r) return;

    push(id);

    int mid = (l + r) >> 1;
    add(u, v, val, id << 1, l, mid);
    add(u, v, val, id << 1 | 1, mid + 1, r);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

void pop(int u, int v, int val, int id = 1, int l = 0, int r = N - 1){
    if(l > r || v < l || r < u) return;
    if(u <= l && r <= v && nodes[id].mn >= val){
        nodes[id].mn = nodes[id].mx = val;
        nodes[id].lz = val;
        return;
    }
    else if(l == r) return;

    push(id);

    int mid = (l + r) >> 1;
    pop(u, v, val, id << 1, l, mid);
    pop(u, v, val, id << 1 | 1, mid + 1, r);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

void get(int finalHeight[], int id = 1, int l = 0, int r = N - 1){
    if(l == r){
        finalHeight[l] = nodes[id].mn;
        return;
    }

    push(id);

    int mid = (l + r) >> 1;
    get(finalHeight, id << 1, l, mid);
    get(finalHeight, id << 1 | 1, mid + 1, r);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
    N = n;
    build();

    for(int i = 0; i < k; ++i){
        if(op[i] == 1) add(left[i], right[i], height[i]);
        else pop(left[i], right[i], height[i]);
    }

    get(finalHeight);
}
