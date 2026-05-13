/******************************************************************************
Link: https://codeforces.com/contest/1991/problem/D
Code: 1991D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-13-11.51.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

bool check_prime(int n){
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return n > 1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);


//    for(int u = 1; u <= n; ++u){
//        for(int v = u + 1; v <= n; ++v){
//            if(check_prime(u ^ v)){
//                cout << u << " " << v << endl;
//            }
//        }
//    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(n == 1){
            cout << "1\n1";
        }
        else if(n == 2){
            cout << "2\n1 2";
        }
        else if(n == 3){
            cout << "2\n1 2 2";
        }
        else if(n == 4){
            cout << "3\n1 2 2 3";
        }
        else if(n == 5){
            cout << "3\n1 2 2 3 3";
        }
        else{
            cout << "4\n";
            for(int i = 1; i <= n; ++i) cout << i % 4 + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
