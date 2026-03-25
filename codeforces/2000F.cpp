/******************************************************************************
Link: https://codeforces.com/contest/2000/problem/F
Code: 2000F
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-24-10.59.13
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Rect{
    int n, m;

    void input(){
        cin >> n >> m;
        if(n > m) swap(n, m);
    }

    pair<int, int> use(){
        if(n == 1 && m == 1){
            --n; --m;
            return {2, 1};
        }


        pair<int, int> res = {1, n};

        --m;
        if(n > m) swap(n, m);

        return res;
    }

    bool valid(){
        return n > 0 && m > 0;
    }

    bool operator < (const Rect& other) const{
        return n > other.n;
    }

    void output() const{
        cerr << n << " " << m << "\n";
    }
};

void solve(){
    int n, k;
    cin >> n >> k;

    vector<Rect> rects(n + 1);
    for(int i = 1; i <= n; ++i){
        rects[i].input();
    }

    priority_queue<Rect> pq;
    for(int i = 1; i <= n; ++i)
        pq.push(rects[i]);

    int res = 0;
    while(k > 0){
        if(pq.empty()) break;

        Rect rect = pq.top();
        pq.pop();

        int C, S;
        tie(C, S) = rect.use();

        cerr << C << " " << S << " ";
        rect.output();

        k -= C;
        res += S;

        if(rect.valid()) pq.push(rect);
    }

    if(k > 0) cout << "-1\n";
    else cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
