/******************************************************************************
Link: https://codeforces.com/contest/2111/problem/C
Code: 2111C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-19-23.14.49
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    arr[n + 1] = -1;

    bool alleq = true;
    for(int i = 1; i <= n; ++i){
        if(i > 1 && arr[i - 1] != arr[i]){
            alleq = false;
            break;
        }
    }

    if(alleq){
        cout << "0\n";
        return;
    }

    int best = INF, l = 1;
    for(int i = 1; i <= n + 1; ++i){
        if(i > 1 && arr[i - 1] != arr[i]){
            int r = i - 1;
            best = min(best, (l - 1) * arr[l] + arr[r] * (n - r));
            l = i;
        }
    }

    cout << best << '\n';
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
