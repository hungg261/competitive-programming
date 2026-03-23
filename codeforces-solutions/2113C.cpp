/******************************************************************************
Link: https://codeforces.com/contest/2113/problem/C
Code: 2113C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-24-14.37.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void test(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> s(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
        s[i] = "#" + s[i];
    }

    vector<vector<int>> preRow(n + 1, vector<int>(m + 1)), preCol(m + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; ++i){
        preRow[i][0] = 0;
        for(int j = 1; j <= m; ++j){
            preRow[i][j] = preRow[i][j - 1] + (s[i][j] == 'g');
        }
    }
    for(int j = 1; j <= m; ++j){
        preCol[j][0] = 0;
        for(int i = 1; i <= n; ++i){
            preCol[j][i] = preCol[j][i - 1] + (s[i][j] == 'g');
        }
    }

    auto getLine = [](int a, int b1, int b2, const vector<vector<int>>& pre){
        if(a <= 0 || a >= (int)pre.size()) return 0;
        b1 = max(1, b1); b2 = max(0, b2);
        b1 = min((int)pre.size() - 1, b1); b2 = min((int)pre[0].size() - 1, b2);

        return pre[a][b2] - pre[a][b1 - 1];
    };

    auto get = [&](int x, int y, int R){
         int res = 0;
         res += getLine(y - R, x - R, x + R - 1, preCol);
         res += getLine(y + R, x - R + 1, x + R, preCol);
         res += getLine(x - R, y - R + 1, y + R, preRow);
         res += getLine(x + R, y - R, y + R - 1, preRow);
         return res;
    };

    int gcnt = 0, res = 1e9;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(s[i][j] == 'g') ++gcnt;
            else if(s[i][j] == '.'){
                res = min(res, get(i, j, k));
            }
        }
    }

    cout << gcnt - res << '\n';
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> s(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
        s[i] = "#" + s[i];
    }

    vector<vector<int>> pre(n + 1, vector<int>(m + 1));
    for(int i = 0; i <= n; ++i) pre[i][0] = 0;
    for(int j = 0; j <= m; ++j) pre[0][j] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (s[i][j] == 'g');
        }
    }

    auto normalize = [&n, &m](int& x, int& y){
        x = max(1, x); y = max(1, y);
        x = min(n, x); y = min(m, y);
    };

    auto get = [&pre, &normalize](int x1, int y1, int x2, int y2){
        normalize(x1, y1); normalize(x2, y2);
        return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
    };

    auto getLost = [&pre, &get](int x, int y, int R){
        return get(x - R + 1, y - R + 1, x + R - 1, y + R - 1);
    };

    int gcnt = 0, lost = 1e9;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(s[i][j] == 'g') ++gcnt;
            else if(s[i][j] == '.'){
                lost = min(lost, getLost(i, j, k));
            }
        }
    }

    cout << gcnt - lost << '\n';
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
