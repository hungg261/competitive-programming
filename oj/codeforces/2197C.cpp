/******************************************************************************
Link: https://codeforces.com/contest/2197/problem/C
Code: 2197C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-24-16.55.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void trau(){
    int p, q;
    cin >> p >> q;

    int turn = 0;
    while(p > 0 || q > 1){
        if(3 * p > 2 * q){
            if(turn == 0){
                if(q - 1 > 1) --q;
                else --p;
            }
            else{
                if(p - 1 > 0) --p;
                else --q;
            }
        }
        else if(3 * p < 2 * q){
            if(turn == 0){
                if(p - 1 > 0) --p;
                else --q;
            }
            else{
                if(q - 1 > 0) --q;
                else --p;
            }
        }
        else{
            cout << "Bob\n";
            return;
        }

        turn ^= 1;
    }

    cout << "Alice\n";
}

void solve(){
    int p, q;
    cin >> p >> q;

    int p3 = p * 3, q2 = q * 2;
    if(p3 > q2){
        if(p3 - q2 >= q - 1){
            cout << "Alice\n";
            return;
        }
        else{
            cout << "Bob\n";
            return;
        }
    }
    else if(p3 < q2){
        cout << "Alice\n";
        return;
    }
    else{
        cout << "Bob\n";
    }
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
