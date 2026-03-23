/******************************************************************************
Link: http://codeforces.com/problemset/problem/2194/D
Code: 2194D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-08-16.36.41
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<vector<int>> pre(m + 1, vector<int>(n + 2));

    int cnt1 = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> arr[i][j];
            cnt1 += arr[i][j] == 1;
        }
    }
    for(int j = 1; j <= m; ++j){
        pre[j][n + 1] = 0;
        for(int i = n; i >= 1; --i){
            pre[j][i] = pre[j][i + 1] + arr[i][j];
        }
    }

    string res;
    int sum = 0;
    int h = 1;
    for(int j = 1; j <= m; ++j){
        while(h <= n){
            if((sum + pre[j][h]) * 2 <= cnt1){
                sum += pre[j][h];
                break;
            }
            else{
                res += "D";
                ++h;
            }
        }
        res += "R";
    }

    while(h <= n){
        res += "D";
        ++h;
    }

    cout << sum * (cnt1 - sum) << '\n';
    cout << res << '\n';
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
