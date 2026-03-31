/******************************************************************************
Link: https://codeforces.com/contest/2180/problem/C
Code: 2180C
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-31-18.51.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    if(k & 1){
        for(int i = 1; i <= k; ++i) cout << n << " ";
        cout << "\n";

        return;
    }

    int mask = 0;
    for(int b = 30; b >= 0; --b){
        if(n >> b & 1){
            if(!mask) mask |= 1 << b;
            else{
                mask |= (1 << b) - 1;
                break;
            }
        }
    }

    cout << mask << " " << (n ^ mask) << " ";
    for(int i = 1; i <= k - 2; ++i) cout << n << " ";
    cout << "\n";
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
