/******************************************************************************
Link: https://codeforces.com/gym/106337/problem/A
Code: Gym_106337A
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-22-20.02.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5;
int a[MAXN + 5], n;

namespace Solve{

void solve(){
    sort(a + 1, a + n + 1);
    long long res = 0, pre = 0;
    for(int i = 1; i <= n; ++i){
        res += 1LL * a[i] * (i - 1) - pre;
        pre += a[i];
    }

    cout << res << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    Solve::solve();

    return 0;
}
