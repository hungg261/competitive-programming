/******************************************************************************
Link: https://codeforces.com/problemset/problem/2121/D
Code: 2121D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-07-21.15.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    stringstream ss;
    int op = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < n; ++j){
            if(a[j] >= a[j + 1]){
                ss << "1 " << j << '\n';
                swap(a[j], a[j + 1]);
                ++op;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < n; ++j){
            if(b[j] >= b[j + 1]){
                ss << "2 " << j << '\n';
                swap(b[j], b[j + 1]);
                ++op;
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        if(a[i] >= b[i]){
            ss << "3 " << i << '\n';
            swap(a[i], b[i]);
            ++op;
        }
    }

    cout << op << '\n';
    cout << ss.str();
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
