/******************************************************************************
Link: https://judge.yosupo.jp/problem/deque
Code: deque
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-11-10.21.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int Q;
    cin >> Q;

    deque<int> dq;
    while(Q--){
        int type;
        cin >> type;

        if(type == 0){
            int x; cin >> x;
            dq.push_front(x);
        }
        else if(type == 1){
            int x; cin >> x;
            dq.push_back(x);
        }
        else if(type == 2){
            dq.pop_front();
        }
        else if(type == 3){
            dq.pop_back();
        }
        else if(type == 4){
            int i; cin >> i;
            cout << dq[i] << "\n";
        }
    }

    return 0;
}
