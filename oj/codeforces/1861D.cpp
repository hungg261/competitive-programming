/******************************************************************************
Link: https://codeforces.com/contest/1861/problem/D
Code: 1861D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-02-17.19.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    arr[0] = 0;

    int cnt = 0, res = 0;
    for(int i = 1; i <= n; ++i){
        if(arr[i - 1] >= arr[i]){
            if(arr[i - 1] == arr[i]){
                if(i - 1 == 1 || i == n){}
                else if(arr[i] == arr[i + 1]) ++res;
                else ++res;
            }
        }
        else{
            ++cnt;
        }
    }

    cout << res + cnt << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
