/******************************************************************************
Link: https://www.codechef.com/START261D/problems/EXSHAKE
Code: EXSHAKE
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-21-21.39.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for(int &ele: a) cin >> ele;

    sort(begin(a), end(a));
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += a[i];
        if(sum * (sum - 1) / 2 > s){
            cout << i << "\n";
            return;
        }
    }

    cout << n << "\n";
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
