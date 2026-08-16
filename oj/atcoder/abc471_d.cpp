/******************************************************************************
Link: https://atcoder.jp/contests/abc471/tasks/abc471_d
Code: abc471_d
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-15-19.05.22
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Battery{
    int x, t;

    bool operator < (const Battery& other) const {
        return x - t < other.x - other.t;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    priority_queue<Battery> pq;
    int V, Q;
    cin >> Q >> V;

    while(Q--){
        int type;
        cin >> type;

        if(type == 1){
            int t, w;
            cin >> t >> w;

            pq.push({w, t});
        }
        else{
            int t;
            cin >> t;

            if(pq.empty()){
                cout << "-1\n";
                continue;
            }

            Battery o = pq.top();
            pq.pop();

            cout << min(V, o.x + (t - o.t)) << "\n";
        }
    }

    return 0;
}
