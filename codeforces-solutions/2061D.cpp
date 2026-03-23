/******************************************************************************
Link: https://codeforces.com/contest/2061/problem/D
Code: 2061D
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-30-18.00.26
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    priority_queue<int> pq;
    multiset<int> mark;
    for(int i = 0; i < n; ++i){
        int ai;
        cin >> ai;

        mark.insert(ai);
    }
    for(int i = 0; i < m; ++i){
        int bi;
        cin >> bi;

        pq.push(bi);
    }

    while(!pq.empty()){
        if(pq.size() > mark.size()){
            cout << "No\n";
            return;
        }

        int cur = pq.top();

        pq.pop();
        if(mark.count(cur)){
            mark.erase(mark.find(cur));
        }
        else{
            if(cur == 1){
                cout << "No\n";
                return;
            }

            pq.push(cur >> 1);
            pq.push(cur + 1 >> 1);
        }
    }

    if(!mark.empty()){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
