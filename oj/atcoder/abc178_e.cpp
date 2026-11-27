/******************************************************************************
Link: https://atcoder.jp/contests/abc178/tasks/abc178_e
Code: abc178_e
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-26-16.30.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5, INF = 1e18;
struct Point{
    int x, y;

    void transform(){
        int u = x + y;
        int v = x - y;

        x = u;
        y = v;
    }

    int chebysev(const Point &other) const {
        return max(abs(x - other.x), abs(y - other.y));
    }

} P[MAXN + 5];
int n;

int f(const Point &A){
    int res = 0;
    for(int i = 1; i <= n; ++i)
        res = max(res, P[i].chebysev(A));

    return res;
}

void solve(){
    int Xmn, Xmx, Ymn, Ymx;
    Xmn = Ymn = INF; Xmx = Ymx = -INF;

    for(int i = 1; i <= n; ++i){
        Xmn = min(Xmn, P[i].x);
        Xmx = max(Xmx, P[i].x);
        Ymn = min(Ymn, P[i].y);
        Ymx = max(Ymx, P[i].y);
    }

    vector<Point> pool = {
        {Xmn, Ymn},
        {Xmn, Ymx},
        {Xmx, Ymn},
        {Xmx, Ymx},
    };

    int ans = 0;
    for(int i = 0; i < (int)pool.size(); ++i){
        ans = max(ans, f(pool[i]));
    }

    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> P[i].x >> P[i].y;
        P[i].transform();
    }

    solve();

    return 0;
}
