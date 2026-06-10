/******************************************************************************
Link: https://atcoder.jp/contests/abc250/tasks/abc250_g
Code: abc250_g
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-12-20.31.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    long long res = 0;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;

        pq.push(cur);

        if(pq.top() < cur){
            int s = pq.top();
            pq.pop();

            res += cur - s;
            pq.push(cur);
        }
    }

    cout << res << "\n";

    return 0;
}
