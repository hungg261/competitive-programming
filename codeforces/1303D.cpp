/******************************************************************************
Link: https://codeforces.com/problemset/problem/1303/D
Code: 1303D
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-04-18.57.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long target; int n;
    cin >> target >> n;

    multiset<int> ms;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        ms.insert(cur);
    }

    int res = 0;
    while(true){
        if(target == 0) break;

        auto it = ms.upper_bound(target);
        if(it != ms.begin()){
            --it;

            target -= *it;
        }
        else if(*it > 1){
            ms.insert(*it / 2);
            ms.insert(*it / 2);
            ++res;
        }
        else{
            cout << "-1\n";
            return;
        }

        ms.erase(it);

        cerr << target << ": "; for(int x: ms) cerr << x << " "; cerr << endl; system("pause");
    }

    cout << res << "\n";
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
