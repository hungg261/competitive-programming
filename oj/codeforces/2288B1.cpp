/******************************************************************************
Link: https://codeforces.com/contest/2288/problem/B1
Code: 2288B1
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-21-21.45.27
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int x, y, m;
    cin >> x >> y >> m;
    string s;
    cin >> s;

    int ans = x + y;
    vector<vector<bool>> cur(105, vector<bool>(105, false));
    cur[x][y] = true;

    for(int i = 0; i < m; ++i){
        vector<vector<bool>> nxt(105, vector<bool>(105, false));
        bool any = false;

        for(int a = 0; a <= 100; ++a){
            for(int b = 0; b <= 100; ++b){
                if(!cur[a][b]) continue;

                if(s[i] == '+'){
                    if(a > 0){
                        nxt[a - 1][b + 1] = true;
                        any = true;
                    }
                    if(b > 0){
                        nxt[a][b + 1] = true;
                        any = true;
                    }
                }
                else{
                    if(a > 0){
                        nxt[a - 1][b] = true;
                        any = true;
                    }
                    if(b > 0){
                        nxt[a + 1][b - 1] = true;
                        any = true;
                    }
                }
            }
        }

        if(!any) break;

        cur.swap(nxt);

        for(int a = 0; a <= 100; ++a){
            for(int b = 0; b <= 100; ++b){
                if(cur[a][b]) ans = max(ans, a + b);
            }
        }
    }

    cout << ans << "\n";
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
