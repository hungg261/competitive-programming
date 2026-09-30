/******************************************************************************
Link: https://www.codechef.com/START258D/problems/STAIRCASE7
Code: STAIRCASE7
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-30-21.38.42
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, a[MAXN + 5];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        mp[a[i] - i]++;
    }

    int res = 0;
    for(const pair<int, int>& p: mp){
//        cerr << p.first << " " << p.second << endl;
        res = max(res, p.second);
    }

    cout << n - res << "\n";
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
