/******************************************************************************
Link: https://codeforces.com/problemset/problem/1030/D
Code: 1030D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-06-15.56.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void println(long long a, long long b){
    cout << a << " " << b << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, m, k;
    cin >> n >> m >> k;

    if(2 * n * m % k != 0){
        cout << "NO\n";
        return 0;
    }

    bool simplified = false;
    if(k % 2 == 0) k /= 2, simplified = true;

    long long g = __gcd(n, k);
    long long a = n / g, b = m / (k / g);

    if(!simplified && a * b != 2 * n * m / k){
        if(a * 2 <= n) a *= 2;
        else b *= 2;
    }

    cout << "YES\n";
    println(0, 0);
    println(a, 0);
    println(0, b);

    return 0;
}
