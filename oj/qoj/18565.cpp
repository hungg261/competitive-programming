/******************************************************************************
Link: https://vjudge.net/problem/QOJ-18565
Code: 18565
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-02-09.22.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, INF = 1e9 + 5;
int n, k, a[MAXN + 5];

namespace Brute{

void solve(){
    array<int, 3> res = {0, 0, -1};
    for(int i = 0; i < n; ++i){
        int mn = INF, mx = -INF;
        for(int j = i; j < n; ++j){
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            if(j - i + 1 >= k)
                res = max(res, {mn + mx, j - i + 1, i});
        }
    }

    cout << res[0] << " " << res[2] << " " << res[2] + res[1] - 1 << "\n";
}

}

namespace Solve{

const int MAXLG = __lg(MAXN) + 1;
int table[MAXN + 5][MAXLG + 5];

int L[MAXN + 5], R[MAXN + 5];

void compute(){
    for(int i = 0; i < n; ++i){
        table[i][0] = a[i];
    }

    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 0; i + (1 << j) - 1 < n; ++i){
            table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }

    vector<int> sta;
    for(int i = 0; i < n; ++i){
        while(!sta.empty() && !(a[sta.back()] < a[i])) sta.pop_back();
        L[i] = sta.empty() ? 0 : sta.back() + 1;
        sta.push_back(i);
    }
    sta.clear();
    for(int i = n - 1; i >= 0; --i){
        while(!sta.empty() && !(a[sta.back()] < a[i])) sta.pop_back();
        R[i] = sta.empty() ? n - 1 : sta.back() - 1;
        sta.push_back(i);
    }
}

int getMax(int l, int r){
    int bit = __lg(r - l + 1);
    return max(table[l][bit], table[r - (1 << bit) + 1][bit]);
}

void solve(){
    compute();

    array<int, 3> res = {-1, -1, -1};
    for(int i = 0; i < n; ++i){
        if(R[i] - L[i] + 1 >= k)
            res = max(res, {a[i] + getMax(L[i], R[i]), R[i] - L[i] + 1, L[i]});
    }

    cout << res[0] << " " << res[2] << " " << res[2] + res[1] - 1 << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    Solve::solve();

    return 0;
}
