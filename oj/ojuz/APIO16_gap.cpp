/******************************************************************************
Link: https://oj.uz/problem/view/APIO16_gap
Code: APIO16_gap
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-06-10.40.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

long long findGap(int T, int N);

#ifndef __________
#include "gap.h"
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"

void MinMax(long long, long long, long long*, long long*);

static void my_assert(int k){ if (!k) exit(1); }

static int subtask_num, N;
static long long A[100001];
static long long call_count;

void MinMax(long long s, long long t, long long *mn, long long *mx)
{
	int lo = 1, hi = N, left = N+1, right = 0;
	my_assert(s <= t && mn != NULL && mx != NULL);
	while (lo <= hi){
		int mid = (lo+hi)>>1;
		if (A[mid] >= s) hi = mid - 1, left = mid;
		else lo = mid + 1;
	}
	lo = 1, hi = N;
	while (lo <= hi){
		int mid = (lo+hi)>>1;
		if (A[mid] <= t) lo = mid + 1, right = mid;
		else hi = mid - 1;
	}
	if (left > right) *mn = *mx = -1;
	else{
		*mn = A[left];
		*mx = A[right];
	}
	if (subtask_num == 1) call_count++;
	else if (subtask_num == 2) call_count += right-left+2;
}

signed main()
{
	FILE *in = stdin, *out = stdout;
	my_assert(2 == fscanf(in, "%d%d", &subtask_num, &N));
	my_assert(1 <= subtask_num && subtask_num <= 2);
	my_assert(2 <= N && N <= 100000);
	for (int i=1;i<=N;i++) my_assert(1 == fscanf(in, "%lld", A+i));
	for (int i=1;i<N;i++) my_assert(A[i] < A[i+1]);
	fprintf(out, "%lld\n", findGap(subtask_num, N));
	fprintf(out, "%lld\n", call_count);
}
#pragma GCC diagnostic pop
#endif // __________

#pragma GCC diagnostic ignored "-Wshadow"
#define int long long

const int MAXVAL = 1e18;

int subtask1(int N){
    vector<int> arr(N);
    int L = 0, R = MAXVAL;

    int head = 0, tail = N - 1;
    while(head <= tail){
        int x, y;
        MinMax(L, R, &x, &y);

        arr[head] = x;
        arr[tail] = y;

        L = x + 1;
        R = y - 1;
        ++head;
        --tail;
    }

    sort(begin(arr), end(arr));
    int best = 0;
    for(int i = 1; i < N; ++i){
        best = max(best, arr[i] - arr[i - 1]);
    }

    return best;
}


int subtask2(int N){
    int L, R; MinMax(0, MAXVAL, &L, &R);
    int k = (R - L - 1) / (N - 1) + 1;

    vector<pair<int, int>> groups;
    groups.emplace_back(-1, L);
    groups.emplace_back(R, -1);

    int best = 0;
    for(int i = L + 1; i <= R - 1; i += k){
        int j = min(R - 1, i + k - 1);

        int x, y;
        MinMax(i, j, &x, &y);
        if(x == -1) continue;
        groups.emplace_back(x, y);
        best = max(best, y - x);
    }

    sort(begin(groups), end(groups));

    int sz = groups.size();
    for(int i = 1; i < sz; ++i){
        if(groups[i].first == -1 || groups[i - 1].second == -1) continue;
        best = max(best, groups[i].first - groups[i - 1].second);
    }
    return best;
}


long long findGap(int32_t T, int32_t N){
    return T == 1 ? subtask1(N) : subtask2(N);
}
