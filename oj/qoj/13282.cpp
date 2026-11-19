/******************************************************************************
Link: https://qoj.ac/problem/13282
Code: 13282
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-19-11.32.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5;
int n, k, a[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;

    int res = LLONG_MIN / 2;
    for(int i = 1; i <= n; ++i){
        if(i >= k) res = max(res, a[i] + i + sum);

        sum += a[i];
        pq.push(a[i]);

        if((int)pq.size() > k - 1){
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << res << "\n";

    return 0;
}
