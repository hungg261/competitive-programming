/******************************************************************************
Link: https://codeforces.com/contest/982/problem/E
Code: 982E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-20-16.12.20
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
    int g = ext_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

void solve(){
    int n, m, x, y, vx, vy;
    cin >> n >> m >> x >> y >> vx >> vy;

    if(vx == 0){
        if(x == 0 || x == n){
            if(vy == 1) cout << x << ' ' << m << '\n';
            else if(vy == -1) cout << x << ' ' << 0 << '\n';
        }
        else cout << "-1\n";
        return;
    }
    else if(vy == 0){
        if(y == 0 || y == m){
            if(vx == 1) cout << n << ' ' << y << '\n';
            else if(vx == -1) cout << 0 << ' ' << y << '\n';
        }
        else cout << "-1\n";
        return;
    }

    if(vx == -1) x = n - x;
    if(vy == -1) y = m - y;

    int k1, k2;
    int g = (ext_gcd(n, m, k1, k2));

    int _c = x - y;
    if(_c % g != 0){
        cout << "-1\n";
        return;
    }

    k1 *= _c / g;
    k2 *= _c / g;
    k2 *= -1;

    int t1 = lround(floor(1.0 * -k1 * g / m)) + 1,
        t2 = lround(floor(1.0 * -k2 * g / n)) + 1;

    int t = max(t1, t2);
    k1 += m / g * t;
    k2 += n / g * t;

    int tarx = k1 % 2 ? n : 0;
    int tary = k2 % 2 ? m : 0;

    if(vx == -1) tarx = n - tarx;
    if(vy == -1) tary = m - tary;

    cout << tarx << ' ' << tary << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
