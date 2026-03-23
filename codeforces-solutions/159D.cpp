/******************************************************************************
Link: https://codeforces.com/problemset/problem/159/D
Code: 159D
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-06-09.39.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2000;
bool ispalin[MAXN + 5][MAXN + 5];
int palcnt[MAXN + 5];
string s;
int n;

void compute(){
    for(int i = 1; i <= n; ++i){
        ispalin[i][i] = true;
        if(i > 1 && s[i - 1] == s[i]) ispalin[i - 1][i] = true;
    }

    for(int len = 3; len <= n; ++len){
        for(int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;

            if(s[i] == s[j]) ispalin[i][j] |= ispalin[i + 1][j - 1];
        }
    }

    for(int r = 1; r <= n; ++r){
        palcnt[r] = palcnt[r - 1];
        for(int l = 1; l <= r; ++l){
            palcnt[r] += ispalin[l][r];
        }
    }
}

void solve(){
    int res = 0;
    for(int j = 1; j <= n; ++j){
        for(int i = 1; i <= j; ++i){
            if(ispalin[i][j])
                res += palcnt[i - 1];
        }
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    n = s.size();
    s = "#" + s;

    compute();
    solve();

    return 0;
}
