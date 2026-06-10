/******************************************************************************
Link: https://cses.fi/problemset/task/3305
Code: 3305
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-11-21.55.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int F = 0, S = 1;

int memo[2][100005];
int n, k;
int ask(int C, int pos){
    if(pos <= 0) return INT_MAX;
    else if(pos > n) return INT_MIN;

    if(memo[C][pos]) return memo[C][pos];

    cout << "FS"[C] << " " << pos << endl;

    int value;
    cin >> value;

    return memo[C][pos] = value;
}

signed main(){
    cin >> n >> k;

    int l = max(0, k - n), r = min(n, k), idx = -1;
    while(l <= r){
        int mid = (l + r) >> 1;

        int L = ask(F, mid),
            R = ask(S, k - mid + 1);

        if(L > R){
            idx = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    assert(idx != -1);

    int res = min(ask(F, idx), ask(S, k - idx));
    cout << "! " << res << endl;

    return 0;
}
