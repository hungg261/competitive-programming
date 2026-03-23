/******************************************************************************
Link: https://codeforces.com/problemset/problem/2065/E
Code: 2065E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-07-19.30.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    auto build = [&k, &n, &m](vector<int> cnt, int c){
        int org = c;

        string S;
        if(cnt[c] < k) return string(1, '#');

        for(int i = 0; i < k; ++i) S += c + '0', --cnt[c];
        for(int j = k; j < n + m; ++j){
            c ^= 1;
            if(cnt[c] == 0){
                if(c == org){
                    if(cnt[c ^ 1] < k) S += string(cnt[c ^ 1], (c ^ 1) + '0');
                    else return string(1, '#');
                }
                else{
                    return string(1, '#');
                }
                break;
            }

            S += c + '0';
            --cnt[c];
        }

        return S;
    };

    string way1 = build({n, m}, 0), way2 = build({n, m}, 1);
    if(way1 != "#") cout << way1 << '\n';
    else if(way2 != "#") cout << way2 << '\n';
    else cout << "-1\n";
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
