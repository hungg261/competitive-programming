/******************************************************************************
Link: https://codeforces.com/contest/1492/problem/D
Code: 1492D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-19-06.56.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, k;
    cin >> a >> b >> k;
    int len = a + b;

    if(b == 0){
        if(k > 0) cout << "No\n";
        else{
            cout << "Yes\n";
            cout << string(len, '0') << "\n";
            cout << string(len, '0') << "\n";
        }
        return;
    }

    string x(len, '0'), y(len, '0');


    int used1 = 0;
    for(int i = 0; i < len; ++i){
        if(used1 < b - 1){
            x[i] = y[i] = '1';
            ++used1;
        }
    }

    for(int i = len - 1; i >= 0; --i){
        int b = len - i;
        if(b <= k + 1){
            if(x[i] == '1'){
                cout << "No\n";
                return;
            }
        }

        if(b == k + 1){
            x[i] = '1';
            y[len - 1] = '1';
            break;
        }
    }

    if(x[0] == '0' || y[0] == '0'){
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    cout << x << "\n";
    cout << y << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
