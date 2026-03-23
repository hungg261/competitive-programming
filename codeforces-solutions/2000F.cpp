/******************************************************************************
Link: https://codeforces.com/contest/2000/problem/F
Code: 2000F
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-23-20.34.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Rect{
    int n, m, idx;

    void input(int i){
        cin >> n >> m;
        idx = i;

        if(n > m) swap(n, m);
    }

    bool operator < (const Rect& other) const{
        return n > other.n || (n == other.n && idx < other.idx);
    }

    int C() const{ return n + m; }
    int S() const{ return n * m; }

    void output() const{
        cerr << idx << ": " << n << " " << m << "\n";
    }
};

void solve(){
    int n, k;
    cin >> n >> k;

    vector<Rect> rects(n + 1);
    for(int i = 1; i <= n; ++i){
        rects[i].input(i);
    }

    priority_queue<Rect> pq;
    for(int i = 1; i <= n; ++i)
        pq.push(rects[i]);

    int res = 0;
    while(k > 0){
        Rect cur = pq.top();
        pq.pop();

        if(cur.C() <= k){
            k -= cur.C();
            res += cur.S();
            continue;
        }


    }


}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
