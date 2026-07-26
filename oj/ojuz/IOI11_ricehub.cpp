/******************************************************************************
Link: https://oj.uz/problem/view/IOI11_ricehub
Code: IOI11_ricehub
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-26-15.26.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "ricehub.h"
#else
int besthub(int R, int L, int X[], long long B);

#define MAX_R  1000000

static int R, L;
static long long B;
static int X[MAX_R];

inline
void my_assert(int e) {if (!e) abort();}

static void read_input()
{
  int i;
  my_assert(3==scanf("%d %d %lld",&R,&L,&B));
  for(i=0; i<R; i++)
    my_assert(1==scanf("%d",&X[i]));
//   my_assert(1==scanf("%d",&solution));
}

int main()
{
  int ans;
  read_input();
  ans = besthub(R,L,X,B);

  printf("%d", ans);

//   if(ans==solution)
//     printf("Correct.\n");
//   else
//     printf("Incorrect.  Returned %d instead of %d.\n",ans,solution);

  return 0;
}

#endif // __________

#pragma GCC diagnostic ignored "-Wshadow"

namespace Brute{

bool check(int R, int X[], long long B, int len){
    for(int i = 0; i + len - 1 < R; ++i){
        vector<int> S(X + i, X + i + len);
        sort(begin(S), end(S));

        int pos = S[len / 2];
        long long sum = 0;

        for(int x: S) sum += abs(pos - x);
        if(sum <= B) return true;

    }

    return false;
}

int besthub(int R, int L, int X[], long long B){
    int lo = 0, hi = R;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(check(R, X, B, mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

}

namespace Solve{

struct FenwickTree{
    int n;
    vector<long long> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    long long get(int idx){
        if(idx <= 0) return 0;

        long long res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    long long get(int l, int r){ return get(r) - get(l - 1); }
};

bool check(int R, int X[], long long B, int len, const vector<int>& values){
    FenwickTree fwt(R);
    FenwickTree fwtSum(R + 1);
    for(int i = 0; i < R; ++i){
        fwt.update(X[i], 1);
        fwtSum.update(X[i], values[X[i] - 1]);

        if(i >= len){
            fwt.update(X[i - len], -1);
            fwtSum.update(X[i - len], -values[X[i - len] - 1]);
        }

        if(i >= len - 1){
            int idx = i - len / 2, pos = X[idx];
            int smaller = fwt.get(pos);
            long long sum = 1LL * smaller * values[pos - 1] - fwtSum.get(pos)
                        + fwtSum.get(pos + 1, R + 1) - 1LL * (len - smaller) * values[pos - 1];

            if(sum <= B) return true;

        }
    }

    return false;
}

int besthub(int R, int L, int X[], long long B){
    vector<int> values;
    for(int i = 0; i < R; ++i)
        values.push_back(X[i]);
    sort(begin(values), end(values));
    for(int i = 0; i < R; ++i){
        X[i] = lower_bound(begin(values), end(values), X[i]) - begin(values) + 1;
    }

    int lo = 0, hi = R;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(check(R, X, B, mid, values)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

}

int besthub(int R, int L, int X[], long long B){
    return Solve::besthub(R, L, X, B);
}
