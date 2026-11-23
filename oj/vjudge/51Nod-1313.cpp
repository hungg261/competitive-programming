/******************************************************************************
Link: https://vjudge.net/problem/51Nod-1313
Code: 51Nod-1313
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-23-21.22.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
string s;

void solve(){
    if(k > n){
        cout << "0\n";
        return;
    }

    int ans = 0;

    vector<int> cnt(n + 1, 0);
    for(int c = n; c > 1; --c){
        vector<int> P(n + 1, 0);

        {
            int curO = 0, pre = 0;
            bool isO = true;
            for(int d = c; d <= n; ++d){
                if(s[d] == 'O'){
                    curO++;
                    if(isO) pre++;
                }
                else{
                    curO = 0;
                    isO = false;
                }

                if(curO >= k) break;
                ++cnt[pre];
            }
        }

        P[0] = cnt[0];
        for(int i = 1; i < k; ++i)
            P[i] += P[i - 1] + cnt[i];

        {
            int b = c - 1;
            int curO = 0, pre = 0;
            bool isO = true;
            for(int a = b; a >= 1; --a){
                if(s[a] == 'O'){
                    curO++;
                    if(isO) pre++;
                }
                else{
                    curO = 0;
                    isO = false;
                }

                if(curO >= k) break;
                ans -= P[k - 1 - pre];
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            int left = n - j;
            ans += left * (left + 1) / 2;
        }
    }

    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k;
    cin >> s;
    n = s.size();
    s = "#" + s;

    for(int i = 1; i <= n; ++i){
        if(s[i] == 'R') s[i] = 'V';
        else if(s[i] == 'G') s[i] = 'O';
        else if(s[i] == 'B') s[i] = 'I';
    }

    solve();

    return 0;
}
