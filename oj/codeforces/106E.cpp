/******************************************************************************
Link: https://codeforces.com/problemset/problem/106/E
Code: 106E
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-12-19.09.38
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const double TIME_LIMIT = 1.0;
const double LIMIT = 1e4, EPS = 1e-6;
const double PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline double Rand(double l, double r){
    return uniform_real_distribution<double>(l, r)(rng);
}

inline double pow2(double x){ return x * x; }

struct Point{
    double x, y, z;

    void randomize(){
        x = Rand(-LIMIT + EPS, LIMIT - EPS);
        y = Rand(-LIMIT + EPS, LIMIT - EPS);
        z = Rand(-LIMIT + EPS, LIMIT - EPS);
    }

    Point move(double _x, double _y, double _z, double k){
        return {x + _x * k, y + _y * k, z + _z * k};
    }

    double dist2(const Point& other) const { return pow2(x - other.x) + pow2(y - other.y) + pow2(z - other.z); }
    double dist(const Point& other) const { return sqrt(dist2(other)); }

    friend istream &operator >> (istream &is, Point &p){ return is >> p.x >> p.y >> p.z; }
    friend ostream &operator << (ostream &os, const Point &p){ return os << p.x << " " << p.y << " " << p.z; }
};
int n;
vector<Point> P;

double find_r2(const Point &o){
    double R = 0;
    for(const Point &p: P){
        R = max(R, p.dist2(o));
    }
    return R;
}

void solve(){
    const int SIZE = 25, NEW_SIZE = 25;
    double COOLING_RATE = 0.995;


    double step = LIMIT;

    pair<double, Point> best = {1e100, {0, 0, 0}};
    vector<pair<double, Point>> pos(SIZE);
    for(int i = 0; i < SIZE; ++i){
        pos[i].second.randomize();
        pos[i].first = find_r2(pos[i].second);

        if(pos[i].first < best.first){
            best = pos[i];
        }
    }

    while(1.0 * clock() / CLOCKS_PER_SEC < TIME_LIMIT){
        if (step < 1e-7){
            step = LIMIT;

            pos[0] = best;
            for(int i = 1; i < SIZE; ++i){
                pos[i].second.randomize();
                pos[i].first = find_r2(pos[i].second);
            }
        }

        for(int i = 0; i < SIZE; ++i){
            for(int j = 0; j < NEW_SIZE; ++j){
                double z = Rand(-1.0, 1.0);
                double phi = Rand(0.0, 2 * PI);
                double r = sqrt(max(0.0, 1.0 - z * z));

                double dx = r * cos(phi);
                double dy = r * sin(phi);
                double dz = z;

                pair<double, Point> cand;
                cand.second = pos[i].second.move(dx, dy, dz, step);
                cand.first = find_r2(cand.second);
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

    cout << fixed << setprecision(10) << best.second << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    P.resize(n);

    for(int i = 0; i < n; ++i){
        cin >> P[i];
    }

    solve();

    return 0;
}
