/******************************************************************************
Link: https://oj.uz/problem/view/JOI25_ho_t2
Code: JOI25_ho_t2
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-06-18.13.01
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
int N, A[MAXN * 2 + 5], B[MAXN * 2 + 5];

namespace Brute{

bool check(long long P, int l, int r){
    for(int i = l; i <= r; ++i){
        if(P < A[i]) return false;
        P += B[i];
    }
    return true;
}

void solve(){
    int ans = INT_MAX;
    for(int i = 1; i <= N; ++i){
        int j = i + N - 1;

        int lo = *min_element(A + i, A + j + 1),
            hi = *max_element(A + i, A + j - 1),
            res = INT_MAX;

        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(check(mid, i, j)){
                res = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        ans = min(ans, res);
    }

    cout << ans << "\n";
}

}

namespace Solve{

long long P[MAXN * 2 + 5];
inline long long f(int i){ return P[i - 1] - A[i]; }

void compute(){
    P[0] = 0;
    for(int i = 1; i <= N * 2; ++i){
        P[i] = P[i - 1] + B[i];
    }
}

void solve(){
    compute();

    deque<int> dq;
    for(int i = 1; i <= N; ++i){
        if(!dq.empty() && i - dq.back() + 1 > N) dq.pop_back();
        while(!dq.empty() && f(dq.front()) >= f(i)) dq.pop_front();
        dq.push_front(i);
    }

    int ans = INT_MAX;
    for(int r = N + 1; r <= N * 2; ++r){
        if(!dq.empty() && r - dq.back() + 1 > N) dq.pop_back();
        while(!dq.empty() && f(dq.front()) >= f(r)) dq.pop_front();
        dq.push_front(r);

        int i = dq.back();
        int l = r - N + 1;

        long long res = A[i] - (P[i - 1] - P[l - 1]);
        ans = min(1LL * ans, res);
    }

    cout << ans << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
        A[i + N] = A[i];
    }
    for(int i = 1; i <= N; ++i){
        cin >> B[i];
        B[i + N] = B[i];
    }

    Solve::solve();

    return 0;
}
