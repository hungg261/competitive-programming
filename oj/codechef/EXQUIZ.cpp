/******************************************************************************
Link: https://www.codechef.com/START261D/problems/EXQUIZ
Code: EXQUIZ
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-21-21.31.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int N, S;
    cin >> N >> S;

    for(int res = 0; res <= N; ++res){
        for(int correct = 0; correct <= res; ++correct){
            if(correct * 4 + (res - correct) * -1 == S){
                cout << res << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
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
