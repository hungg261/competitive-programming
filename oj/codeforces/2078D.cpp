/******************************************************************************
Link: https://codeforces.com/contest/2078/problem/D
Code: 2078D
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-06-11.22.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Doors{
    char op[2];
    int v[2];

    friend istream& operator >> (istream& is, Doors& D){
        for(int d = 0; d < 2; ++d)
            is >> D.op[d] >> D.v[d];
        return is;
    }

    int get(int cur, int d){
        switch (op[d]){
            case '+': return v[d];
            case 'x': return cur * (v[d] - 1);
            default: exit(-2);
        }
    }
};

void solve(){
    int n;
    cin >> n;

    vector<Doors> D(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> D[i];
    }

    vector<array<int, 2>> dp(n + 2);
    dp[n + 1][0] = dp[n + 1][1] = 1;
    for(int i = n; i >= 1; --i){
        for(int j = 0; j < 2; ++j){
            switch (D[i].op[j]){
                case '+': {
                    dp[i][j] = dp[i + 1][j];
                    break;
                }
                case 'x': {
                    dp[i][j] = dp[i + 1][j] + (D[i].v[j] - 1) * max(dp[i + 1][0],
                                                                    dp[i + 1][1]);
                    break;
                }
                default: exit(-1);
            }
        }
    }

    int res[2] = {1, 1};
    for(int i = 1; i <= n; ++i){
        int delta = D[i].get(res[0], 0) + D[i].get(res[1], 1);

        if(dp[i + 1][0] > dp[i + 1][1]) res[0] += delta;
        else res[1] += delta;
    }

    cout << res[0] + res[1] << "\n";
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
