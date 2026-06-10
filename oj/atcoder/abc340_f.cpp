/******************************************************************************
Link: https://atcoder.jp/contests/abc340/tasks/abc340_f
Code: abc340_f
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-08-21.18.41
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int extended_gcd(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

pair<int, int> solve(int A, int B, int C){
    int x, y;
    int g = extended_gcd(A, B, x, y);

    if(C % g != 0){
        return {-1, -1};
    }

    int x0 = x * C / g,
        y0 = y * C / g;

    return {x0, y0};
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("abc340_f.INP","r",stdin);
    //freopen("abc340_f.OUT","w",stdout);

    int A, B;
    cin >> A >> B;

    pair<int, int> res1 = solve(-B, A, 2), res2 = solve(-B, A, -2);
    if(res1.first != -1) cout << res1.first << ' ' << res1.second << '\n';
    else if(res2.first != -1) cout << res2.first << ' ' << res2.second << '\n';
    else{
        cout << "-1\n";
    }

    return 0;
}
