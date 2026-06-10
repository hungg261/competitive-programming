/******************************************************************************
Link: https://codeforces.com/contest/2117/problem/E
Code: 2117E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-28-19.54.49
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    auto check = [&n](const vector<int>& A, const vector<int>& B){
        vector<bool> mark(n + 1, false);
        for(int i = n - 1; i >= 0; --i){
            if(mark[B[i]] || A[i] == B[i]) return i + 1;

            if(i + 1 < n) mark[A[i + 1]] = true;
            mark[B[i]] = true;
        }

        return 0;
    };

    cout << max(check(a, b), check(b, a)) << '\n';
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
