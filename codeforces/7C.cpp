/******************************************************************************
Link: https://codeforces.com/problemset/problem/7/C
Code: 7C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-05-19.42.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int extended_gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;


    int x0, y0;
    int g = extended_gcd(A, B, x0, y0);

    C *= -1;
    if(C % g != 0) cout << "-1\n";
    else{
        int x = C / g * x0;
        int y = C / g * y0;

        cout << x << " " << y << "\n";
    }

    return 0;
}
