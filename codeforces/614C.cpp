/******************************************************************************
Link: https://codeforces.com/contest/614/problem/C
Code: 614C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-18-18.51.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

using Point = complex<long long>;

void input(Point& p){
    int x, y;
    cin >> x >> y;

    p = {x, y};
}

long long dot(const Point& A, const Point& B){ return (conj(A) * B).real(); }
long long cross(const Point& A, const Point& B){ return (conj(A) * B).imag(); }

long long orient(const Point& A, const Point& B, const Point& C){
    return cross(B - A, C - B);
}

long long sqdist(const Point& A, const Point& B){
    return norm(A - B);
}

long long pow2(long long x){ return x * x; }

double dist_to_seg(const Point& C, const Point& A, const Point& B){
    if(dot(C - A, B - A) < 0) return sqrt(sqdist(C, A));
    if(dot(C - B, A - B) < 0) return sqrt(sqdist(C, B));

    if(orient(A, B, C) == 0) return 0;
    return 1.0 * abs(orient(A, B, C)) / sqrt(sqdist(A, B));
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    Point O;
    input(O);

    vector<Point> P(n);
    double smallest = 1e99, largest = -1e99;
    for(Point& p: P){
        input(p);

        largest = max(largest, sqrt(sqdist(O, p)));
    }
    for(int i = 0; i < n; ++i){
        int j = (i + 1) % n;
        smallest = min(smallest, dist_to_seg(O, P[i], P[j]));
    }

    cout << fixed << setprecision(20) << (largest * largest - smallest * smallest) * acos(-1) << "\n";

    return 0;
}
