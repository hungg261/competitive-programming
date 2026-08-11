/******************************************************************************
Link: https://coding.fit.hcmus.edu.vn/problem/war
Code: war
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-11-08.42.26
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    deque<int> L1, L2;
    vector<int> sta1, sta2;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        L1.push_back(cur);
    }
    for(int i = 1; i <= m; ++i){
        int cur; cin >> cur;
        L2.push_back(cur);
    }

    auto check = [&]() -> string {
        if(L1.empty() && L2.empty()) return "draw";
        else if(L1.empty()) return "mike";
        else if(L2.empty()) return "you";

        return "";
    };

    int counter = 0;
    while(true){
        if(++counter >= 100000){
            cout << "draw\n";
            return;
        }

        if(check() != ""){
            cout << check() << "\n";
            return;
        }

        int top1 = L1.front(), top2 = L2.front();
        L1.pop_front(); L2.pop_front();
        sta1.push_back(top1); sta2.push_back(top2);

        if(top1 == top2){
            for(int _ = 0; _ < 3; ++_){
                if(check() != ""){
                    cout << check() << "\n";
                    return;
                }

                sta1.push_back(L1.front());
                sta2.push_back(L2.front());
                L1.pop_front(); L2.pop_front();
            }
        }
        else if(top1 > top2){
            for(int x: sta1) L1.push_back(x);
            for(int x: sta2) L1.push_back(x);
            sta1.clear(); sta2.clear();
        }
        else if(top1 < top2){
            for(int x: sta2) L2.push_back(x);
            for(int x: sta1) L2.push_back(x);
            sta1.clear(); sta2.clear();
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
