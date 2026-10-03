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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int, int> furthest(int u, int bound = n - 1){
    pair<int, int> best = {0, u};
    vector<int> order(n); iota(begin(order), end(order), 1);
    shuffle(begin(order), end(order), rng);

    int left = n - 1;
    for(int v: order){
        if(u == v) continue;
        --left;

        if(ask(u, v, best.first + 1)){
            ++best.first;
            int lo = best.first + 1, hi = bound;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(ask(u, v, mid)){
                    best.first = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }

            best.second = v;
        }
        bound = min(bound, best.first + left);
        if(best.first == bound) break;
    }

    return best;
}

int dist(int u, int v){
    int lo = 0, hi = n - 1, d = 0;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(ask(u, v, mid)){
            d = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    return d;
}

void solve(){
    asked.clear();
    cin >> n;

    int temp, u; tie(temp, u) = furthest(1);
    int d, v; tie(d, v) = furthest(u, min(n - 1, temp * 2));

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
