/******************************************************************************
Link: https://codeforces.com/contest/866/problem/D
Code: 866D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-12-19.55.45
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
