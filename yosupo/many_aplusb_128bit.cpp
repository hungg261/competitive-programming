/******************************************************************************
Link: https://judge.yosupo.jp/problem/many_aplusb_128bit
Code: many_aplusb_128bit
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-27-20.42.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

__int128 to_int128(string num){
    bool is_neg = num[0] == '-';
    if(is_neg) num.erase(num.begin());

    __int128 res = 0;
    for(const char& c: num){
        res = res * 10 + c - '0';
    }
    return res * (is_neg ? -1 : 1);
}

void print(__int128 x){
    if(x < 0){
        cout << "-";
        print(-x);
        return;
    }

    if(x < 10){
        cout << (int)x;
        return;
    }

    print(x / 10);
    cout << (int)(x % 10);
}

void solve(){
    string _a, _b;
    cin >> _a >> _b;

    __int128 a = to_int128(_a), b = to_int128(_b);
    print(a + b);
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
