/******************************************************************************
Link: https://codeforces.com/problemset/problem/1767/D
Code: 1767D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-05-21.20.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n;
string s;

bool check(int target){
    vector<pair<int, int>> suf(n + 1);
    suf[n] = {0, 0};
    for(int i = n - 1; i >= 0; --i){
        suf[i] = suf[i + 1];
        if(s[i] == '0') ++suf[i].first;
        else ++suf[i].second;
    }

    int L = target - 1, R = (1 << n) - target;
    if(L < suf[0].first || R < suf[0].second) return false;

    for(int i = 0; i < n; ++i){
        if(s[i] == '0') --R;
        else --L;

        int tL, tR;
        tie(tR, tL) = suf[i + 1];

        cerr << L << ' ' << R << '\n';
        if(L < tL || R < tR) return false;
        int loss = (L - tL) + (R - tR);

        int newL = max(tL, L - (L - tL) / 2 * 2);
        loss -= L - newL;

        cerr << "af: " << L << ' ' << R << '\n';
    }

    return true;
}

void solve(){
    cerr << check(3) << '\n';
//    for(int i = 1; i <= (1 << n); ++i){
//        if(check(i)){
//            cout << i << ' ';
//        }
//    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> s;

    solve();

    return 0;
}
