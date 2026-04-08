/******************************************************************************
Link: https://codeforces.com/problemset/problem/1851/F
Code: 1851F
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-07-15.03.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
pair<int, int> arr[MAXN + 5];
int n, k;

pair<int, int> f(int a, int b){
    int res = 0, x = 0;
    for(int bit = k - 1; bit >= 0; --bit){
        int ba = (a >> bit & 1), bb = (b >> bit & 1);
        if(ba == bb){
            res |= 1 << bit;

            if(ba == 0) x |= 1 << bit;
        }
    }
    return {res, x};
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        arr[i] = {cur, i};
    }

    sort(arr + 1, arr + n + 1);

    int res = 1;
    for(int i = 2; i < n; ++i){
        if(f(arr[i].first, arr[i + 1].first) > f(arr[res].first, arr[res + 1].first)){
            res = i;
        }
    }

    cout << arr[res].second << " " << arr[res + 1].second << " " << f(arr[res].first, arr[res + 1].first).second << "\n";
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
