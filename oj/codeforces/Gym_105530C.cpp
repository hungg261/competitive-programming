/******************************************************************************
Link: https://codeforces.com/gym/105530/problem/C
Code: Gym_105530C
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-25-09.50.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = LLONG_MAX / 4;
int g(int n, const vector<int> &x, const vector<int> &y, const vector<int> &z){
    int ans = 0;

    int best[8] = {};
    for(int j = 0; j < 8; ++j) best[j] = -INF;

    for(int mask = 0; mask < 8; ++mask){
        for(int i = 1; i <= n; ++i){
            int cur = 0;
            if(mask & 1) cur += x[i];
            else cur -= x[i];
            if(mask & 2) cur += y[i];
            else cur -= y[i];
            if(mask & 4) cur += z[i];
            else cur -= z[i];

            best[mask] = max(best[mask], cur);
        }
    }

    for(int i = 1; i <= n; ++i){
        int res = 0;
        for(int mask = 0; mask < 8; ++mask){
            int cur = 0;
            if(mask & 1) cur += x[i];
            else cur -= x[i];
            if(mask & 2) cur += y[i];
            else cur -= y[i];
            if(mask & 4) cur += z[i];
            else cur -= z[i];

            res = max(res, best[mask] - cur);
        }

        ans += res;
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;

    vector<int> x, y, z;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int cur; cin >> cur;

            x.push_back(cur);
            y.push_back(i);
            z.push_back(j);
        }
    }

    int sz = x.size();
    x.insert(begin(x), 0);
    y.insert(begin(y), 0);
    z.insert(begin(z), 0);

    cout << g(sz, x, y, z) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
