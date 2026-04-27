/******************************************************************************
Link: https://codeforces.com/contest/1366/problem/D
Code: 1366D
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-27-09.16.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXVAL = 1e7;
int res[MAXVAL + 5];

void compute(){
    for(int i = 2; i * i <= MAXVAL; ++i){
        bool i_chan = i % 2 == 0;
        for(int j = i * i; j <= MAXVAL; j += i){
            int k = j / i;
            if(k <= 1 || (i_chan && k % 2 == 0)) continue;

            if(__gcd(i, k) == 1){
                res[j] = i;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    compute();

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i) cout << (res[a[i]] > 0 ? res[a[i]] : -1) << " "; cout << "\n";
    for(int i = 1; i <= n; ++i) cout << (res[a[i]] > 0 ? a[i] / res[a[i]] : -1) << " "; cout << "\n";

    return 0;
}
