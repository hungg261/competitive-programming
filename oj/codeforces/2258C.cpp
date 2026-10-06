/******************************************************************************
Link: https://codeforces.com/problemset/problem/2258/C
Code: 2258C
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-03-16.24.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n;
map<tuple<int, int, int>, int> asked;

int ask(int u, int v, int d){
    if(d > n - 1) return 0;

    if(u > v) swap(u, v);

    tuple<int, int, int> p = {u, v, d};
    if(asked.count(p)){
        return asked[p];
    }

    cout << "? " << u << " " << v << " " << d << endl;

    int STATUS; cin >> STATUS;
    return asked[p] = STATUS;
}

void ans(int u, int v, int d){
    cout << "! " << u << " " << v << " " << d << endl;
}

pair<int, int> furthest(int u, int st = 0){
    pair<int, int> best = {st, 1};

    for(int v = 1; v <= n; ++v){
        if(u == v) continue;

        if(ask(u, v, best.first + 1)){
            ++best.first;
            while(best.first + 1 <= n - 1 && ask(u, v, best.first + 1)){
                ++best.first;
            }
            best.second = v;
        }
    }

    return best;
}

void solve(){
    asked.clear();
    cin >> n;

    int d_temp, u; tie(d_temp, u) = furthest(1);
    int d, v; tie(d, v) = furthest(u, d_temp);

    ans(u, v, d);
}

signed main(){

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
