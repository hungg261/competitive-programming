/******************************************************************************
Link: https://oj.uz/problem/view/JOI14_secret
Code: JOI14_secret
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-20-17.29.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "secret.h"
#else
#ifndef SECRET_H_
#define SECRET_H_

void Init(int N, int A[]);
int Query(int L, int R);

int Secret(int X, int Y);

#endif  /* SECRET_H_ */


#include <stdio.h>
#include <stdlib.h>

#define MAX_N                  1000
#define MAX_Q                 10000
#define MAX_VALUE        1000000000

static int N;
static int A[MAX_N];
static int Q;
static int L[MAX_Q];
static int R[MAX_Q];

static int secret_count;

int Secret(int X, int Y) {
  ++secret_count;
  if (!(0 <= X && X <= MAX_VALUE)) {
    fprintf(stderr, "Wrong Answer [1]\n");
    exit(0);
  }
  if (!(0 <= Y && Y <= MAX_VALUE)) {
    fprintf(stderr, "Wrong Answer [1]\n");
    exit(0);
  }
  return (X + 2 * (Y / 2) < MAX_VALUE) ? (X + 2 * (Y / 2)) : MAX_VALUE;
}

signed main() {
  int i, j;
  int secret_count_by_init;
  int max_secret_count_by_query = 0;

  if (1 != scanf("%d", &N)) {
    fprintf(stderr, "error: cannot read N.\n");
    exit(1);
  }
  if (!(1 <= N && N <= MAX_N)) {
    fprintf(stderr, "error: N is out of bounds.\n");
    exit(1);
  }
  for (i = 0; i < N; ++i) {
    if (1 != scanf("%d", &A[i])) {
      fprintf(stderr, "error: cannot read A[%d].\n", i);
      exit(1);
    }
    if (!(0 <= A[i] && A[i] <= MAX_VALUE)) {
      fprintf(stderr, "error: A[%d] is out of bounds.\n", i);
      exit(1);
    }
  }
  if (1 != scanf("%d", &Q)) {
    fprintf(stderr, "error: cannot read Q.\n");
    exit(1);
  }
  if (!(0 <= Q && Q <= MAX_Q)) {
    fprintf(stderr, "error: Q is out of bounds.\n");
    exit(1);
  }
  for (j = 0; j < Q; ++j) {
    if (2 != scanf("%d%d", &L[j], &R[j])) {
      fprintf(stderr, "error: cannot read L[%d] and R[%d].\n", j, j);
      exit(1);
    }
    if (!(0 <= L[j] && L[j] <= R[j] && R[j] <= N - 1)) {
      fprintf(stderr,
              "error: L[%d] and R[%d] do not satisfy the constraints.\n",
              j, j);
      exit(1);
    }
  }

  secret_count = 0;
  Init(N, A);
  secret_count_by_init = secret_count;

  for (j = 0; j < Q; ++j) {
    secret_count = 0;
    printf("%d\n", Query(L[j], R[j]));
    if (max_secret_count_by_query < secret_count) {
      max_secret_count_by_query = secret_count;
    }
  }

  fprintf(stderr, "number of calls to Secret by Init : %d\n",
          secret_count_by_init);
  fprintf(stderr, "maximum number of calls to Secret by Query : %d\n",
          max_secret_count_by_query);

  return 0;
}
#endif

const int MAXN = 1000, MAXLG = __lg(MAXN) + 1;
int a[MAXN + 5], n;
int table[MAXN + 5][MAXLG + 5];
void compute(int lg, int L, int R){
    if(L > R) return;
    else if(L == R){
        table[L][lg] = a[L];
        return;
    }

    int mid = (L + R) >> 1;
    table[mid][lg] = a[mid];
    for(int i = mid - 1; i >= L; --i){
        table[i][lg] = Secret(a[i], table[i + 1][lg]);
    }

    table[mid + 1][lg] = a[mid + 1];
    for(int i = mid + 2; i <= R; ++i){
        table[i][lg] = Secret(table[i - 1][lg], a[i]);
    }

    compute(lg + 1, L, mid);
    compute(lg + 1, mid + 1, R);
}

void Init(int N, int A[]) {
    n = N;
    for(int i = 0; i < n; ++i)
        a[i] = A[i];
    compute(0, 0, n - 1);
}

int get(int lg, int l, int r, int u, int v){
    if(l == r) return a[l];

    int mid = (l + r) >> 1;
    if(u <= mid && mid < v)
        return Secret(table[u][lg], table[v][lg]);

    if(v <= mid)
        return get(lg + 1, l, mid, u, v);
    else return get(lg + 1, mid + 1, r, u, v);
}

int Query(int L, int R) {
  return get(0, 0, n - 1, L, R);
}

