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

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<pair<Point, int>> P(n);
    for(int i = 0; i < n; ++i){
        long long x, y;
        cin >> x >> y;

        P[i] = {{x, y}, i};
    }

    sort(begin(P), end(P), [&](auto& x, auto& y){
            return arg(x.first) < arg(y.first);
         });

    pair<double, int> best = {-1e100, -1};
    for(int i = 0; i < n; ++i){
        int j = (i + 1) % n;
        best = max(best, {1.0 * dot(P[i].first, P[j].first) / sqrt(norm(P[i].first) * norm(P[j].first)), i});
    }

    cout << P[best.second].second + 1 << " " << P[(best.second + 1) % n].second + 1 << "\n";

    return 0;
}
