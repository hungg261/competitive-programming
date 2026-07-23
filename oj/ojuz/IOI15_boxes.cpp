/******************************************************************************
Link: https://oj.uz/problem/view/IOI15_boxes
Code: IOI15_boxes
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-23-20.42.45
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "boxes.h"
#else
#ifndef boxes_h
#define boxes_h

long long delivery(int N, int K, int L, int p[]);

#endif

static inline int _readInt() {
    int x; cin >> x;
    return x;
}

signed main() {
    int N, K, L, i;
    N = _readInt();
    K = _readInt();
    L = _readInt();

    int *p = (int*)malloc(sizeof(int) * (unsigned int)N);

    for (i = 0; i < N; i++) {
        p[i] = _readInt();
    }

    printf("%lld\n", delivery(N, K, L, p));
    return 0;
}
#endif // __________

const int INF = 1e9;
long long delivery2(int N, int K, int L, int p[]);
long long delivery(int N, int K, int L, int p[]) {
    if(N == K || K == 1){

    vector<long long> dpL(N), dpR(N);
    for(int i = 0; i < N; ++i){
        int last = max(-1, i - K);
        dpL[i] = (last >= 0 ? dpL[last] : 0) + min({INT_MAX, p[i] * 2});
    }
    for(int i = N - 1; i >= 0; --i){
        int last = min(N, i + K);
        dpR[i] = (last < N ? dpR[last] : 0) + min({INT_MAX, (L - p[i]) * 2});
    }

//    for(int i = 0; i < N; ++i){
//        cerr << p[i] << " " << dpL[i] << " " << dpR[i] << endl;
//    }

    long long res = 1LL * (N + K - 1) / K * L;
    for(int i = -1; i < N; ++i){
        res = min(res, (i >= 0 ? dpL[i] : 0) + (i + 1 < N ? dpR[i + 1] : 0));
    }

//    for(int i = 0; i < N - 1; ++i){
//        cerr << dpL[i] << " " << dpR[i + 1] << "\n";
//    }
    return res;
    }
    else return delivery2(N, K, L, p);
}

long long delivery2(int N, int K, int L, int p[]) {
    vector<long long> dpL(N), dpR(N);
    for(int i = 0; i < N; ++i){
        int last = max(-1, i - K);
        dpL[i] = (last >= 0 ? dpL[last] : 0) + min({L, (L - (last + 1 >= 0 ? p[last + 1] : -1)) * 2, p[i] * 2});
    }
    for(int i = N - 1; i >= 0; --i){
        int last = min(N, i + K);
        dpR[i] = (last < N ? dpR[last] : 0) + min({L, (L - p[i]) * 2, (last - 1 < N ? p[last - 1] : -1) * 2});
    }

//    for(int i = 0; i < N; ++i){
//        cerr << p[i] << " " << dpL[i] << " " << dpR[i] << endl;
//    }

    long long res = 1LL * (N + K - 1) / K * L;
    for(int i = 0; i < N; ++i){
        res = min(res, dpL[i] + dpR[(i + 1) % N]);
    }

//    for(int i = 0; i < N - 1; ++i){
//        cerr << dpL[i] << " " << dpR[i + 1] << "\n";
//    }
    return res;
}

