#include <bits/stdc++.h>
using namespace std;

__int128 extended_euclid(__int128 a, __int128 b, __int128 &x1, __int128 &y1) {
    if (b == 0) {
        x1 = 1; y1 = 0;
        return a;
    }
    __int128 u1, v1;
    __int128 d = extended_euclid(b, a % b, u1, v1);
    x1 = v1;
    y1 = u1 - (a / b) * v1;
    return d;
}


__int128 ceil_div(__int128 num, __int128 den) {
    if(num >= 0) return (num + den - 1) / den;
    return  num / den;
}

void output(__int128 x1){
    if(x1 < 0){
        putchar('-');
        x1 = -x1;
    }

    if(x1 > 9) output(x1 / 10);
    putchar(x1 % 10 + '0');
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C;
    cin >> A >> B >> C;

    /////////////////////////////////

    __int128 x1, y1;
    __int128 d = extended_euclid(A, B, x1, y1);


    if (C % d != 0) {
        cout << "-1\n";
        return 0;
    }

    __int128 t1 = ceil_div(-C * x1, B), t2 = ceil_div(C * y1, A);

    __int128 ans = C * (x1 - y1) / d + (B + A) / d * max(t1, t2);
    output(ans); putchar('\n');

    return 0;
}