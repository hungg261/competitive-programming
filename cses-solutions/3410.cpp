/******************************************************************************
Link: https://cses.fi/problemset/task/3410
Code: 3410
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-26-16.15.58
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("3410.INP","r",stdin);
    //freopen("3410.OUT","w",stdout);

    int n;
    cin >> n;

    int maxVal[4] = {-INF, -INF, -INF, -INF};
    int res = -INF;

    for(int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y;

        maxVal[0] = max(maxVal[0], - x - y);
        maxVal[1] = max(maxVal[1], - x + y);
        maxVal[2] = max(maxVal[2], + x - y);
        maxVal[3] = max(maxVal[3], + x + y);

        res = max(res, + x + y + maxVal[0]);
        res = max(res, + x - y + maxVal[1]);
        res = max(res, - x + y + maxVal[2]);
        res = max(res, - x - y + maxVal[3]);

        cout << res << '\n';
    }

    return 0;
}
