/******************************************************************************
Link: https://coding.fit.hcmus.edu.vn/problem/galateasdiet
Code: galateasdiet
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-09-16.56.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int powmod(int a, int b, int m = MOD){
    a %= m;
    int res = 1 % m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

const int MAXK = 10000;
int N, M, K, A[MAXK + 5], B[MAXK + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> K;

    int res = 1;

    A[0] = 0;
    B[0] = -1;
    for(int i = 1; i <= K; ++i){
        cin >> A[i] >> B[i];
    }

    for(int i = 1; i <= K; ++i){
        if(A[i - 1] + 1 == A[i] && B[i] == B[i - 1]) res = 0;
        res = res * powmod(N - 1, A[i] - A[i - 1] - 1) % MOD;
    }

    if(A[1] > 1){
        res = res * N % MOD;
    }

    cout << res << "\n";

    return 0;
}
