/******************************************************************************
Link: https://codeforces.com/contest/1775/problem/C
Code: 1775C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-05-20.00.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXLG = 60;

void solve(){
    int n, x;
    cin >> n >> x;

    int res = 0;
    bool allx_0 = true;
    for(int b = 0; b <= MAXLG; ++b){
        int bit_n = n >> b & 1,
            bit_x = x >> b & 1;

        if(bit_n == 0 && bit_x == 1){
            cout << "-1\n";
            return;
        }
        else if(bit_n == 1 && bit_x == 0){
            if(!allx_0){
                cout << "-1\n";
                return;
            }

            int nsb;
            for(nsb = b; n >> nsb & 1; ++nsb){
                if(x >> nsb & 1){
                    cout << "-1\n";
                    return;
                }
            }

            int last_b = n & ((1LL << (b + 1)) - 1);
            int next_b = 1LL << (b + 1);
            res = max(res, next_b - last_b);
        }

        if(bit_x) allx_0 = false;
    }

    cout << n + res << "\n";
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
