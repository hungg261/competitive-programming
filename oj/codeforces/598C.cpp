/******************************************************************************
Link: https://codeforces.com/problemset/problem/598/C
Code: 598C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-21-15.18.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

using Point = complex<long long>;
long long pow2(long long x){ return x * x; }
long long dot(const Point& A, const Point& B){ return (conj(A) * B).real(); }
long long cross(const Point& A, const Point& B){ return (conj(A) * B).imag(); }
long long norm2(const Point& A){ return pow2(A.real()) + pow2(A.imag()); }

int halfPlane(const Point& p) {
    if(p.imag() == 0) return p.real() < 0;
    return p.imag() < 0;
}

int sign(long long x){
    if(x < 0) return -1;
    if(x > 0) return 1;
    return 0;
}

bool smaller(const Point& A, const Point& B, const Point& C, const Point& D){
    long long dotAB = dot(A, B);
    long long dotCD = dot(C, D);

    int sAB = sign(dotAB);
    int sCD = sign(dotCD);

    if(sAB != sCD) return sAB > sCD;

    __int128 lhs = (__int128)pow2(dotAB) * norm2(C) * norm2(D);
    __int128 rhs = (__int128)pow2(dotCD) * norm2(A) * norm2(B);

    if(sAB >= 0) return lhs > rhs;
    return lhs < rhs;
}

bool smaller(const pair<pair<Point, int>, pair<Point, int>>& v1, const pair<pair<Point, int>, pair<Point, int>>& v2){
    return smaller(v1.first.first, v1.second.first, v2.first.first, v2.second.first);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<pair<Point, int>> P(n);
    for(int i = 0; i < n; ++i){
        long long x, y;
        cin >> x >> y;

        P[i] = {{x, y}, i + 1};
    }

    sort(begin(P), end(P), [&](const auto& a, const auto& b){
        int ha = halfPlane(a.first);
        int hb = halfPlane(b.first);
        if(ha != hb) return ha < hb;
        return cross(a.first, b.first) > 0;
    });

    auto f = [&](const pair<Point, int>& p1, const pair<Point, int>& p2) -> double {
        return 1.0 * dot(p1.first, p2.first) / sqrt(norm(p1.first) * norm(p2.first));
    };

    pair<pair<Point, int>, pair<Point, int>> best;
    for(int i = 0; i < n; ++i){
        int j = (i + 1) % n;

        if(i == 0) best = {P[i], P[j]};
        else if(smaller({P[i], P[j]}, best)){
            best = {P[i], P[j]};
        }
    }

    cout << best.first.second << " " << best.second.second << "\n";

    return 0;
}
