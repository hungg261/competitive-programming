/******************************************************************************
Link: https://codeforces.com/contest/1311/problem/D
Code: 1311D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-03-14.57.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e8;
const int LIM = 2e4;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    auto calc = [&a, &b, &c](int _a, int _b, int _c){
        return abs(a - _a) + abs(b - _b) + abs(c - _c);
    };

    array<int, 3> res = {-INF, -INF, -INF};
    int min_diff = INT_MAX;
    for(int new_a = 1; new_a <= LIM; ++new_a){
        for(int new_b = new_a; new_b <= LIM; new_b += new_a){
            int c_floor = c / new_b * new_b, c_ceil = (c + new_b - 1) / new_b * new_b;
            int new_c = max(new_b, c - c_floor < c_ceil - c ? c_floor : c_ceil);

            int new_diff = calc(new_a, new_b, new_c);
            if(new_diff < min_diff){
                res = {new_a, new_b, new_c};
                min_diff = new_diff;
            }
        }
    }

    cout << min_diff << "\n";
    cout << res[0] << " " << res[1] << " " << res[2] << "\n";
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
