/******************************************************************************
Link: https://codeforces.com/problemset/problem/2067/C
Code: 2067C
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-26-22.29.12
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    int res = 1e9;
    int add = 9;

    auto check = [](int x) -> bool {
        while(x > 0){
            if(x % 10 == 7) return true;
            x /= 10;
        }
        return false;
    };

    for(int r = 0; r < 12; ++r){
        int temp = n;
        for(int c = 0; c < 12; ++c){
            if(check(temp)) res = min(res, c);
            temp += add;
        }

        add = add * 10 + 9;
    }

    cout << res << "\n";
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
