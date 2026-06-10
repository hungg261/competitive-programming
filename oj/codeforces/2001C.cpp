/******************************************************************************
Link: https://codeforces.com/problemset/problem/2001/C
Code: 2001C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-23-17.43.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

set<pair<int, int>> edges;
set<pair<int, int>> trace;
set<int> unused;
void Try(int a, int b){
    if(trace.find({a, b}) != trace.end()) return;
    cout << "? " << a << " " << b << endl;
    trace.insert({a, b});

    int x;
    cin >> x;

    if(x == -1){
        exit(0);
    }

    if(x == a || x == b){
        if(a > b) swap(a, b);

        edges.insert({a, b});
        unused.erase(a);
        unused.erase(b);
        return;
    }

    Try(a, x);
    Try(b, x);
}

void solve(){
    int n;
    cin >> n;

    edges.clear();
    unused.clear();
    trace.clear();

    for(int i = 2; i <= n; ++i){
        unused.insert(i);
    }

    while(!unused.empty()){
        Try(1, *unused.begin());
    }

    cout << "! ";
    for(const pair<int, int>& e: edges){
        cout << e.first << ' ' << e.second << ' ';
    }
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
