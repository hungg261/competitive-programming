/******************************************************************************
Link: https://judge.yosupo.jp/problem/predecessor_problem
Code: predecessor_problem
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-28-21.01.57
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int N, Q;
    cin >> N >> Q;

    string T;
    cin >> T;

    set<int> S;
    for(int i = 0; i < N; ++i)
        if(T[i] == '1') S.insert(i);

    while(Q--){
        int type; cin >> type;

        if(type == 0){
            int k; cin >> k;
            S.insert(k);
        }
        else if(type == 1){
            int k; cin >> k;
            S.erase(k);
        }
        else if(type == 2){
            int k; cin >> k;
            cout << (S.find(k) != S.end()) << "\n";
        }
        else if(type == 3){
            int k; cin >> k;

            auto it = S.lower_bound(k);
            if(it == S.end()) cout << "-1\n";
            else cout << (*it) << "\n";
        }
        else if(type == 4){
            int k; cin >> k;

            auto it = S.upper_bound(k);
            if(it == S.begin()) cout << "-1\n";
            else cout << (*prev(it)) << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
