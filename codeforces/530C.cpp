/******************************************************************************
Link: https://codeforces.com/problemset/problem/530/C
Code: 530C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-02-22.10.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int ext_gcd(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = ext_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    int _x, _y;
    int g = ext_gcd(a, b, _x, _y);

    if(c % g != 0){
        cout << "0\n";
        return;
    }

    int x0 = _x * (c / g);
    int y0 = _y * (c / g);

    int t_min = floor(1.0 * -x0 * g / b) + 1;
    int t_max = ceil(1.0 * y0 * g / a) - 1;

    if(t_min > t_max){
        cout << "0\n";
        return;
    }

    cout << (t_max - t_min + 1) << '\n';
    for(int t = t_min; t <= t_max; ++t){
        int x = x0 + b / g * t;
        int y = y0 - a / g * t;

        cout << x << ' ' << y << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
