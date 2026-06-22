/******************************************************************************
Link: https://oj.uz/problem/view/IOI13_cave
Code: IOI13_cave
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-22-08.48.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "cave.h"
#else
int tryCombination(int S[]);
void answer(int S[], int D[]);
void exploreCave(int N);

#define MAX_N 5000
#define MAX_CALLS 70000

#define fail(s, x...) do { \
		fprintf(stderr, s "\n", ## x); \
		exit(1); \
	} while(0)

/* Symbol obfuscation */
#define N koala
#define realS kangaroo
#define realD possum
#define inv platypus
#define num_calls echidna

static int N;
static int realS[MAX_N];
static int realD[MAX_N];
static int inv[MAX_N];
static int num_calls;

void answer(int S[], int D[]) {
    int i;
    int correct = 1;
    for (i = 0; i < N; ++i)
        if (S[i] != realS[i] || D[i] != realD[i]) {
            correct = 0;
            break;
        }

    if (correct)
        printf("CORRECT\n");
    else
        printf("INCORRECT\n");

    for (i = 0; i < N; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", S[i]);
    }
    printf("\n");

    for (i = 0; i < N; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", D[i]);
    }
    printf("\n");

    exit(0);
}

int tryCombination(int S[]) {
    int i;

    if (num_calls >= MAX_CALLS) {
        printf("INCORRECT\nToo many calls to tryCombination().\n");
        exit(0);
    }
    ++num_calls;

    for (i = 0; i < N; ++i)
        if (S[inv[i]] != realS[inv[i]])
            return i;
    return -1;
}

int init() {
    cin >> N;

    int i;
    for (i = 0; i < N; ++i) {
        cin >> realS[i];
    }
    for (i = 0; i < N; ++i) {
        cin >> realD[i];
        inv[realD[i]] = i;
    }

    num_calls = 0;
    return N;
}
#undef N

signed main() {
    int N;
	N = init();
	exploreCave(N);
    printf("INCORRECT\nYour solution did not call answer().\n");
	return 0;
}

#endif // __________

const int MAXN = 5000;
int S[MAXN + 5], D[MAXN + 5];
bool found[MAXN + 5];

void fill(int l, int r, int value){
    for(int i = l; i < r; ++i)
        if(!found[i]) S[i] = value;
}

void print(int a[], int N){ for(int i = 0; i < N; ++i) cerr << a[i] << " "; cerr << endl; }

void exploreCave(int N){
    memset(found, 0, sizeof found);
    memset(S, 0, sizeof S);
    for(int i = 0; i < N; ++i){
        fill(0, N, 0);
        int out = tryCombination(S);
        if(out == -1) out = N;

        int open_state = out == i;
        assert(out >= i);

        int lo = 0, hi = N - 1;
        while(lo < hi){
            int mid = (lo + hi + 1) >> 1;
            fill(lo, mid, 1 - open_state);
            fill(mid, hi + 1, open_state);

            int _out = tryCombination(S);
            if(_out == -1) _out = N;

            if(_out > i) lo = mid;
            else hi = mid - 1;

        }

        D[lo] = i;
        S[lo] = open_state;
        found[lo] = true;
    }

    answer(S, D);
}
