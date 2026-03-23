/******************************************************************************
Link: https://codeforces.com/problemset/problem/2169/D1
Code: 2169D1
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-04-21.04.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 1e12;
int x, y, k;

int tknp(int a, int i){
    int l = 0, r = MAX / a + 1, res = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(a * mid <= i + mid - 1){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return res;
}

void solve(){
    cin >> x >> y >> k;

    int len = MAX;
    for(int turn = 1; turn <= x; ++turn){
        int loss = len / y;
        len -= loss;
    }

    if(len < k){
        cout << "-1\n";
        return;
    }

    int res = k;
    for(int turn = 1; turn <= x; ++turn){
        int add = tknp(y, res);
        res += add;
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
