/******************************************************************************
Link: https://codeforces.com/contest/1396/problem/A
Code: 1396A
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-20-20.43.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];

    cout << 1 << ' ' << 1 << '\n';
    cout << -arr[1] << '\n';

    if(n > 1){
        cout << 1 << ' ' << n << '\n';
        cout << 0 << ' ';
        for(int i = 2; i <= n; ++i) cout << -arr[i] * n << ' '; cout << '\n';

        cout << 2 << ' ' << n << '\n';
        for(int i = 2; i <= n; ++i) cout << arr[i] * (n - 1) << ' '; cout << '\n';
    }
    else{
        cout << 1 << ' '<< 1 << '\n';
        cout << 0 << '\n';
        cout << 1 << ' '<< 1 << '\n';
        cout << 0 << '\n';
    }

    return 0;
}
