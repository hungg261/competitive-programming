/******************************************************************************
Link: https://oj.vnoi.info/problem/icpc26_mn_a
Code: icpc26_mn_a
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-25-16.21.15
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m, x, y, vx, vy;

int _floor(int a, int b){
    if(a >= 0) return a / b;

    a *= -1;
    return -(a + b - 1) / b;
}

void query(){
    int t;
    cin >> t;

    int cx = x + vx * t,
        cy = y + vy * t;

    int fx = _floor(cx, n), fy = _floor(cy, m);
    cx %= n; cy %= m;
    if(cx < 0) cx += n;
    if(cy < 0) cy += m;

    pair<int, int> res;
    if(fx % 2 == 0){
        if(fy % 2 == 0){
            res = {cx, cy};
        }
        else{
            res = {cx, m - cy};
        }
    }
    else{
        if(fy % 2 == 0){
            res = {n - cx, cy};
        }
        else{
            res = {n - cx, m - cy};
        }
    }

    cout << res.first + 1 << " " << res.second + 1 << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> x >> y >> vx >> vy;
    --n; --m; --x; --y;

    int q;
    cin >> q;

    while(q--){
        query();
    }

    return 0;
}
