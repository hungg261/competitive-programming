/******************************************************************************
Link: https://oj.uz/problem/view/JOI19_ho_t1
Code: JOI19_ho_t1
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-22-12.00.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 3000;
string S[MAX + 1];
int H, W;

int cntI[MAX + 1][MAX + 1];
void solve(){
    for(int j = 1; j <= W; ++j){
        int cnt = 0;
        for(int i = H; i >= 1; --i){
            if(S[i][j] == 'I') ++cnt;
            else if(S[i][j] == 'J') cntI[i][j] = cnt;
        }
    }

    long long res = 0;
    for(int i = 1; i <= H; ++i){
        long long pre = 0;
        for(int j = 1; j <= W; ++j){
            pre += cntI[i][j];
            if(S[i][j] == 'O') res += pre;
        }
    }

    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> H >> W;
    for(int i = 1; i <= H; ++i){
        cin >> S[i];
        S[i] = " " + S[i];
    }

    solve();

    return 0;
}
