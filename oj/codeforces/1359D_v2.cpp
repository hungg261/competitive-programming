/******************************************************************************
Link: https://codeforces.com/contest/1359/problem/D
Code: 1359D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-08-08.20.12
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int INF = 50;
const int MAXN = 1e5, MAXVAL = 30;

int kadane(const vector<int>& arr){
    int maxSum = -INF, cur = -INF;
    for(int e: arr){
        cur = max(cur + e, e);
        maxSum = max(maxSum, cur);
    }

    return maxSum;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int ans = 0;
    for(int maxV = -MAXVAL; maxV <= MAXVAL; ++maxV){
        vector<int> temp = a;
        for(int i = 0; i < n; ++i)
            if(temp[i] > maxV) temp[i] = -INF;

        ans = max(ans, kadane(temp) - maxV);
    }

    cout << ans << "\n";

    return 0;
}
