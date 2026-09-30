/******************************************************************************
Link: https://www.codechef.com/START258D/problems/SEATING7
Code: SEATING7
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-30-21.31.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int N, M, K;
    cin >> N >> M >> K;

    set<int> O;
    for(int i = 1; i <= M; ++i){
        int cur; cin >> cur;
        O.insert(cur);
    }

    int cur = 1;
    for(int j = 0; j < K; ++j){
        while(O.count(cur)) ++cur;
        cout << cur++ << " ";
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}
