/******************************************************************************
Link: https://marisaoj.com/problem/294
Code: 294
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-08-17.37.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

template<typename T> T pow2(T x){ return x * x; }

struct Point{
    int x, y;

    double dist(Point& other) const {
        return sqrt(pow2(x - other.x) + pow2(y - other.y));
    }

    friend istream& operator >> (istream& is, Point& p){
        return is >> p.x >> p.y;
    }
};

int AREA(Point A, Point B, Point C){
    return abs((A.x - B.x) * C.y + (B.x - C.x) * A.y + (C.x - A.x) * B.y);
}

Point A, B, C;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> A >> B >> C;

    int S = AREA(A, B, C);

    if(S == 0){
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    cout << fixed << setprecision(10) << A.dist(B) + B.dist(C) + C.dist(A) << "\n";

    return 0;
}
