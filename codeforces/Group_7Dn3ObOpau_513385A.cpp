/******************************************************************************
Link: https://codeforces.com/group/7Dn3ObOpau/contest/513385/problem/A
Code: Group_7Dn3ObOpau_513385A
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-13-09.58.01
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        priority_queue<int, vector<int>, less<int>> pq;
        long long sum = 0;
        for(int i = 1; i <= n; ++i){
            int cur; cin >> cur;

            if(sum > cur){
                sum -= cur;
                pq.push(cur);
            }
            else if(!pq.empty() && cur < pq.top()){
                sum += pq.top() * 2;
                pq.pop();

                sum -= cur;
                pq.push(cur);
            }
            else sum += cur;
        }

        cout << pq.size() << "\n";
    }

    return 0;
}
