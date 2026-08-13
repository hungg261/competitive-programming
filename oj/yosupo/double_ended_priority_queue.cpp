/******************************************************************************
Link: https://judge.yosupo.jp/problem/double_ended_priority_queue
Code: double_ended_priority_queue
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-12-16.40.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    multiset<int> ms;
    for(int i = 1; i <= N; ++i){
        int cur; cin >> cur;
        ms.insert(cur);
    }

    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            int x; cin >> x;
            ms.insert(x);
        }
        else if(type == 1){
            auto it = ms.begin();
            cout << (*it) << "\n";
            ms.erase(it);
        }
        else if(type == 2){
            auto it = prev(ms.end());
            cout << (*it) << "\n";
            ms.erase(it);
        }
    }

    return 0;
}
