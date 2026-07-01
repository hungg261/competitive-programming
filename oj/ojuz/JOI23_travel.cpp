/******************************************************************************
Link: https://oj.uz/problem/view/JOI23_travel
Code: JOI23_travel
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-01-11.54.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5, MAXQ = 2e5;
int N, X[MAXN + 5], Q, S[MAXN + 5];

namespace Brute{

int calc(int st){
    set<int> S(X + 1, X + N + 1);
    S.insert(INT_MIN);
    S.insert(INT_MAX);
    long long res = 0;
    while((int)S.size() > 2){
        auto R = S.lower_bound(st);
        auto L = prev(S.upper_bound(st));

        long long distL = 1LL * st - (*L), distR = 1LL * (*R) - st;
        if(distL <= distR){
            res += distL;
            st = *L;
            S.erase(L);
        }
        else{
            res += distR;
            st = *R;
            S.erase(R);
        }
    }

    return res;
}

void solve(){
    for(int i = 1; i <= Q; ++i){
        cout << calc(S[i]) << "\n";
    }
}

}

namespace Solve{

const int MAXLG = __lg(MAXN) + 1;
int T[2][MAXN + 5][MAXLG + 5];
int P[2][MAXN + 5];

namespace L{

void compute(){
    for(int i = 1; i <= N; ++i){
        P[0][i] = P[0][i - 1] + (X[i] - X[i - 1]);
    }

    auto sumDiff = [&](int l, int r){ return P[0][r] - P[0][l - 1]; };

    for(int i = 1; i <= N; ++i){
        int lo = i + 1, hi = N;
        T[0][i][0] = i;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(sumDiff(i + 1, mid) < X[i] - X[i - 1]){
                T[0][i][0] = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
    }
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= N; ++i){
            T[0][i][j] = max(T[0][i][j - 1], T[0][i + (1 << (j - 1))][j - 1]);
        }
    }
}

int get(int l, int r){
    int bit = __lg(r - l + 1);
    return max(T[0][l][bit], T[0][r - (1 << bit) + 1][bit]);
}

}

namespace R{

void compute(){
    for(int i = 1; i <= N; ++i){
        P[1][i] = P[1][i - 1] + (X[i + 1] - X[i]);
    }

    auto sumDiff = [&](int l, int r){ return P[1][r] - P[1][l - 1]; };

    for(int i = 1; i <= N; ++i){
        int lo = 1, hi = i - 1;
        T[1][i][0] = i;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(sumDiff(mid, i - 1) <= X[i + 1] - X[i]){
                T[1][i][0] = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
    }
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= N; ++i){
            T[1][i][j] = min(T[1][i][j - 1], T[1][i + (1 << (j - 1))][j - 1]);
        }
    }
}

int get(int l, int r){
    int bit = __lg(r - l + 1);
    return min(T[1][l][bit], T[1][r - (1 << bit) + 1][bit]);
}

}

int calc(int i){
    long long res = 0;
    int L = i, R = i;
    while(R - L + 1 < N){
        int distL = X[L] - X[L - 1], distR = X[R + 1] - X[R];

        if(distL <= distR){
            int lo = 1, hi = L, o = 1;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(L::get(mid, R) >= R + 1){
                    o = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }

            L = o;
            res += X[R] - X[L];
        }
        else{
            int lo = R, hi = N, o = N;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(R::get(L, mid) <= L - 1){
                    o = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }

            R = o;
            res += X[R] - X[L];
        }
    }

    return res;
}

void solve(){
    X[0] = LLONG_MIN / 2; X[N + 1] = LLONG_MAX / 2;
    L::compute();
    R::compute();

    for(int i = 1; i <= Q; ++i){
        auto sL = prev(upper_bound(X + 1, X + N + 1, S[i]));
        auto sR = lower_bound(X + 1, X + N + 1, S[i]);

        int diffL = S[i] - *sL, diffR = *sR - S[i];
        int res = diffL <= diffR ? diffL + calc(sL - X) : diffR + calc(sR - X);
        cout << res << "\n";
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> X[i];

    cin >> Q;
    for(int i = 1; i <= Q; ++i)
        cin >> S[i];

    Solve::solve();

    return 0;
}
