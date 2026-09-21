/******************************************************************************
Link: https://codeforces.com/gym/104150/problem/B
Code: Gym_104150B
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-21-18.29.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e5, MAXM = 4e5;
int n, m, k;
int a[MAXN + 5], x[MAXM + 5];

namespace Solve{

int P[MAXN + 5];
int L[MAXN + 5];

void compute(){
    P[0] = 0;
    for(int i = 1; i <= n; ++i){
        P[i] = P[i - 1];
        if(i > 1 && a[i] == a[i - 1]) ++P[i];
    }

    L[0] = 1;
    for(int i = 1; i <= n; ++i){
        L[i] = L[i - 1];
        if(a[i - 1] > a[i]) L[i] = i;
    }
}

void solve(){
    compute();

    for(int i = 1; i <= m; ++i){
        int res = L[x[i]];

        {
            int lo = 1, hi = x[i], o = -1;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(P[x[i]] - P[mid] <= k){
                    o = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }

            res = max(res, o);
        }

        cout << res << " ";
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    cin >> m >> k;
    for(int i = 1; i <= m; ++i){
        cin >> x[i];
    }

    Solve::solve();

    return 0;
}
