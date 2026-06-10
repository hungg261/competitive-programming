/******************************************************************************
Link: https://codeforces.com/contest/2159/problem/A
Code: 2159A
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-24-13.13.01
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n * 2 + 1, -1);
    vector<int> S = {1};

    int cnt = 0;
    for(int i = 2; i <= n * 2; ++i){
        cout << "? ";
        cout << (int)S.size() + 1 << ' ';
        for(int ele: S) cout << ele << ' ';
        cout << i << endl;

        ++cnt;
        if(cnt > n * 3) exit(0);

        int x;
        cin >> x;

        if(x == 0) S.push_back(i);
        else a[i] = x;
    }

    S.clear();
    for(int i = 1; i <= n * 2; ++i)
        if(a[i] != -1) S.push_back(i);

    for(int i = 1; i <= n * 2; ++i){
        if(a[i] != -1) continue;

        cout << "? ";
        cout << (int)S.size() + 1 << ' ';
        for(int ele: S) cout << ele << ' ';
        cout << i << endl;

        ++cnt;
        if(cnt > n * 3) exit(0);

        int x;
        cin >> x;

        a[i] = x;
    }

    cout << "! ";
    for(int i = 1; i <= n * 2; ++i)
        cout << a[i] << ' ';
    cout << endl;
}

signed main(){

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
