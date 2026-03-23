/******************************************************************************
Link: https://codeforces.com/contest/2124/problem/D
Code: 2124D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-15-12.07.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    vector<int> temp = arr;
    sort(begin(temp) + 1, end(temp));

    int x = temp[k - 1];
    vector<int> b;
    int sz = n;
    for(int i = 1; i <= n; ++i){
        if(arr[i] <= x) b.push_back(arr[i]);
        else --sz;
    }

    int l = 0, r = (int)b.size() - 1;
    while(l < r){
        if(b[l] == b[r]) ++l,--r;
        else if(b[l] == x) ++l,--sz;
        else if(b[r] == x) --r,--sz;
        else{
            cout << "NO\n";
            return;
        }
    }

    if(sz >= k - 1) cout << "YES\n";
    else cout << "NO\n";
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
