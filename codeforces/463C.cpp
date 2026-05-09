/******************************************************************************
Link: https://codeforces.com/contest/463/problem/C
Code: 463C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-09-09.13.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2000, MAXDIAG = MAXN * 2 - 1;
int n;
int a[MAXN + 5][MAXN + 5];
int dcheo[2][MAXDIAG + 5];

template<typename T> void maximize(T& x, const T& new_x){ x = max(x, new_x); }

struct Point{
    int x, y;

    Point(int _x = -1, int _y = -1): x(_x), y(_y){}

    bool operator < (const Point& other) const {
        return x < other.x;
    }

    friend ostream& operator << (ostream& os, const Point& p){
        return os << p.x << " " << p.y;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            dcheo[0][i - j + n] += a[i][j];
            dcheo[1][i + j - 1] += a[i][j];
        }
    }

    pair<int, Point> res[2] = {};
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            a[i][j] = dcheo[0][i - j + n] + dcheo[1][i + j - 1] - a[i][j];
            maximize(res[i + j & 1], make_pair(a[i][j], Point(i, j)));
        }
    }

    cout << res[0].first + res[1].first << "\n";
    cout << res[0].second << " " << res[1].second;


    return 0;
}
