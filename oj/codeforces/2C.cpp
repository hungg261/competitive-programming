/******************************************************************************
Link: https://codeforces.com/problemset/problem/2/C
Code: 2C
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-13-21.09.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const double TIME_LIMIT = 1.0, OVERHEAD = 0.05, RUN_TIME = TIME_LIMIT - OVERHEAD;
const double INF = 1e100, LIMIT = 1e4, EPS = 1e-9;
const double PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline double Rand(double l, double r){ return uniform_real_distribution<double>(l, r)(rng); }
inline double pow2(double x){ return x * x; }

struct Point{
    double x, y, r;

    Point move(double dx, double dy, double k){
        return {x + dx * k, y + dy * k, r};
    }

    double angle(const Point &other) const {
        return asin(r / dist(other));
    }

    bool contains(const Point &other) const {
        return dist(other) <= r;
    }

    void randomize(){
        x = Rand(-LIMIT + EPS, LIMIT - EPS);
        y = Rand(-LIMIT + EPS, LIMIT - EPS);
    }

    double dist2(const Point& other) const { return pow2(x - other.x) + pow2(y - other.y); }
    double dist(const Point& other) const { return sqrt(dist2(other)); }

    friend istream &operator >> (istream& os, Point &p){ return os >> p.x >> p.y >> p.r; }
    friend ostream &operator << (ostream& os, const Point &p){ return os << p.x << " " << p.y; }
};
int n;
vector<Point> P;

double get(const Point &o){
    for(const Point &p: P){
        if(o.dist2(p) <= pow2(p.r)) return INF;
    }

    double d0 = o.dist(P[0]) / P[0].r;
    double d1 = o.dist(P[1]) / P[1].r;
    double d2 = o.dist(P[2]) / P[2].r;

    return pow2(d0 - d1) + pow2(d1 - d2) + pow2(d2 - d0);
}

void solve(){
    clock_t START_TIME = clock();
    const int SIZE = 25, NEW_SIZE = 25;
    double COOLING_RATE = 0.995;

    double step = LIMIT;

    pair<double, Point> best = {INF, {0, 0, 0}};
    vector<pair<double, Point>> pos(SIZE);

    double best_d0 = INF;
    Point final_ans = {0, 0, 0};

    for(int i = 0; i < SIZE; ++i){
        pos[i].second.randomize();
        pos[i].first = get(pos[i].second);

        if(pos[i].first < best.first){
            best = pos[i];
        }
    }

    while(1.0 * (clock() - START_TIME) / CLOCKS_PER_SEC < RUN_TIME){
        if(step < EPS){
            for(int i = 0; i < SIZE; ++i){
                if(pos[i].first < 1e-11){
                    double cur_d0 = pos[i].second.dist(P[0]) / P[0].r;
                    if(cur_d0 < best_d0){
                        best_d0 = cur_d0;
                        final_ans = pos[i].second;
                    }
                }
            }

            step = LIMIT;
            best.first = INF;

            for(int i = 0; i < SIZE; ++i){
                pos[i].second.randomize();
                pos[i].first = get(pos[i].second);

                if(pos[i].first < best.first){
                    best = pos[i];
                }
            }
        }

        for(int i = 0; i < SIZE; ++i){
            for(int j = 0; j < NEW_SIZE; ++j){
                double rnd = Rand(0, 2 * PI);
                double dx = cos(rnd);
                double dy = sin(rnd);

                pair<double, Point> cand;
                cand.second = pos[i].second.move(dx, dy, step);
                cand.first = get(cand.second);
                if(cand.first < pos[i].first){
                    pos[i] = cand;

                    if(pos[i].first < best.first){
                        best = pos[i];
                    }
                }
            }
        }

        step *= COOLING_RATE;
    }

    for(int i = 0; i < SIZE; ++i){
        if(pos[i].first < 1e-5){
            double cur_d0 = pos[i].second.dist(P[0]) / P[0].r;
            if(cur_d0 < best_d0){
                best_d0 = cur_d0;
                final_ans = pos[i].second;
            }
        }
    }

    if(best_d0 != INF){
        cout << fixed << setprecision(5) << final_ans.x << " " << final_ans.y << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    n = 3;
    P.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> P[i];
    }

    solve();

    return 0;
}
