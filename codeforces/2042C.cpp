/******************************************************************************
Link: https://codeforces.com/contest/2042/problem/C
Code: 2042C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-02-20.19.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    string f;
    cin >> f;

    vector<int> s;
    int sum = 0;
    for(int i = n - 1; i > 0; --i){
        sum += f[i] == '1' ? 1 : -1;
        if(sum > 0) s.push_back(sum);
    }

    sort(begin(s), end(s), greater<int>());
    int res = 0;
    for(int ele: s){
        ++res;
        k -= ele;

        if(k <= 0){
            cout << res + 1 << '\n';
            return;
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
