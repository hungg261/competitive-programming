/******************************************************************************
Link: https://vjudge.net/problem/SPOJ-RUNAWAY
Code: RUNAWAY
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-11-13.26.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline double Rand(double l, double r){ return uniform_real_distribution<double>(l, r)(rng); }
inline double pow2(double x){ return x * x; }

struct Point{
    double x, y;

    Point move(const Point &vec, double k){
        return {x + vec.x * k, y + vec.y * k};
    }

    double dist(const Point &other) const {
        return sqrt(pow2(x - other.x) + pow2(y - other.y));
    }

    friend istream &operator >> (istream& os, Point &p){ return os >> p.x >> p.y; }
    friend ostream &operator << (ostream& os, const Point &p){ return os << p.x << " " << p.y; }
};

inline void bound(Point &p, int X, int Y){
    if(p.x > X) p.x = X;
    if(p.y > Y) p.y = Y;
    if(p.x < 0) p.x = 0;
    if(p.y < 0) p.y = 0;
}

void solve(const double LIMIT){
    int X, Y, M;
    cin >> X >> Y >> M;

    vector<Point> P(M);
    for(int i = 0; i < M; ++i){
        cin >> P[i];
    }

    auto get = [&](const Point &point) -> double {
        double d = 1e100;
        for(const Point &p: P){
            d = min(d, p.dist(point));
        }
        return d;
    };

    const double COOLING_RATE = 0.9;
    const int NUM_CAND = 30;

    vector<Point> cand(NUM_CAND);
    vector<double> bdist(NUM_CAND);
    for(int i = 0; i < NUM_CAND; ++i){
        cand[i] = {Rand(0, X), Rand(0, Y)};
        bdist[i] = get(cand[i]);
    }

    double step = max(X, Y);

    while(1.0 * clock() / CLOCKS_PER_SEC < LIMIT){
        for(int i = 0; i < NUM_CAND; ++i){
            for(int k = 0; k < NUM_CAND; ++k){
                double angle = Rand(0.0, 2 * PI);
                Point dir = {cos(angle), sin(angle)};
                Point p = cand[i].move(dir, step);
                bound(p, X, Y);

                double cur = get(p);
                if(cur > bdist[i]){
                    bdist[i] = cur;
                    cand[i] = p;
                }
            }
        }
        step *= COOLING_RATE;
    }

    int best = 0;
    for(int i = 1; i < NUM_CAND; ++i){
        if(bdist[i] > bdist[best]){
            best = i;
        }
    }

    cout << fixed << setprecision(1);
    cout << "The safest point is (" << cand[best].x << ", " << cand[best].y << ").\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    const double TOTAL_TL = 13.0;
    const double OVERHEAD = 0.5;

    for(int rem = t; rem >= 1; --rem){
        double cur_time = 1.0 * clock() / CLOCKS_PER_SEC;
        double rem_time = (TOTAL_TL - OVERHEAD) - cur_time;
        double budget = max(0.01, rem_time / rem);
        double end_time = cur_time + budget;

        solve(end_time);
    }

    return 0;
}
