/******************************************************************************
Link: https://marisaoj.com/problem/295
Code: 295
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-08-17.53.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Point{
    int x, y;

    Point operator - (const Point& other) const {
        return {x - other.x, y - other.y};
    }

    int cross(const Point& other) const {
        return x * other.y - y * other.x;
    }

    friend istream& operator >> (istream& is, Point& p){
        return is >> p.x >> p.y;
    }
};

int sign(Point A, Point B, Point C){
    int o = (B - A).cross(C - A);
    if(o == 0) return 0;
    else if(o > 0) return 1;
    else if(o < 0) return -1;
    else throw "I am gay";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--){
        Point A, B, C, D;
        cin >> A >> B >> C >> D;

        int o1 = sign(A, B, C) * sign(A, B, D);
        int o2 = sign(C, D, A) * sign(C, D, B);

        if(o1 == 0 && o2 == 0){
            if(max(A.x, C.x) <= min(B.x, D.x) && max(A.y, C.y) <= min(B.y, D.y)) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            cout << (o1 <= 0 && o2 <= 0 ? "YES" : "NO") << "\n";
        }
    }


    return 0;
}
