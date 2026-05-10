/******************************************************************************
Link: https://judge.yosupo.jp/problem/sort_points_by_argument
Code: sort_points_by_argument
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-10-12.10.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

using Point = complex<long long>;
using dPoint = complex<long double>;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    cout << fixed << setprecision(10);

    vector<Point> P(n);
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;

        P[i] = {x, y};
    }

    sort(begin(P), end(P), [](Point& A, Point& B){
         return arg(dPoint(A.real(), A.imag())) < arg(dPoint(B.real(), B.imag()));
    });

    for(int i = 0; i < n; ++i){
        cout << P[i].real() << " " << P[i].imag() << "\n";
    }

    return 0;
}
