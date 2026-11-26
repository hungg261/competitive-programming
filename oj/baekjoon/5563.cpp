/******************************************************************************
Link: https://acmicpc.net/problem/5563
Code: 5563
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-26-08.40.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3e5, INF = 1e18;
struct Point{
    int x, y;

    void transform(){
        int u = x + y;
        int v = x - y;

        x = u;
        y = v;
    }

    int chebysev(const Point &p) const {
        return max(abs(x - p.x), abs(y - p.y));
    }
};

int n;
vector<Point> P;

int get(const Point &A, const Point &B){
    int D = 0;
    for(int i = 0; i < n; ++i){
        D = max(D, min(P[i].chebysev(A), P[i].chebysev(B)));
    }
    return D;
}

void solve(){
    int Xmn, Xmx, Ymn, Ymx;
    Xmn = Ymn = INF; Xmx = Ymx = -INF;
    for(int i = 0; i < n; ++i){
        Xmn = min(Xmn, P[i].x);
        Xmx = max(Xmx, P[i].x);
        Ymn = min(Ymn, P[i].y);
        Ymx = max(Ymx, P[i].y);
    }

    vector<Point> pool;
    pool.push_back({Xmn, Ymn});
    pool.push_back({Xmn, Ymx});
    pool.push_back({Xmx, Ymn});
    pool.push_back({Xmx, Ymx});

    int ans = INF;
    for(int i = 0; i < (int)pool.size(); ++i){
        for(int j = i + 1; j < (int)pool.size(); ++j){
            ans = min(ans, get(pool[i], pool[j]));
        }
    }

    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    P.resize(n);

//    for(int i = 0; i < n; ++i){
//        cin >> P[i].x;
//    }
//    for(int i = 0; i < n; ++i){
//        cin >> P[i].y;
//    }

    for(int i = 0; i < n; ++i){
        cin >> P[i].x >> P[i].y;
        P[i].transform();
    }

    solve();

    return 0;
}
