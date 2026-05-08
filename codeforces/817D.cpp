/******************************************************************************
Link: https://codeforces.com/contest/817/problem/D
Code: 817D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-08-08.29.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int n, a[MAXN + 5];

int L[MAXN + 5], R[MAXN + 5];
template<typename func1, typename func2> void compute(func1 cmp1, func2 cmp2){
    vector<int> sta;
    for(int i = 1; i <= n; ++i){
        while(!sta.empty() && !cmp1(a[sta.back()], a[i])) sta.pop_back();
        L[i] = sta.empty() ? 0 : sta.back();
        sta.push_back(i);
    }

    sta.clear();

    for(int i = n; i >= 1; --i){
        while(!sta.empty() && !cmp2(a[sta.back()], a[i])) sta.pop_back();
        R[i] = sta.empty() ? n + 1 : sta.back();
        sta.push_back(i);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    long long res = 0;
    compute(greater<int>(), greater_equal<int>());
    for(int i = 1; i <= n; ++i){
        res += 1LL * a[i] * (R[i] - i) * (i - L[i]);
    }

    compute(less<int>(), less_equal<int>());
    for(int i = 1; i <= n; ++i){
        res -= 1LL * a[i] * (R[i] - i) * (i - L[i]);
    }

    cout << res << "\n";

    return 0;
}
