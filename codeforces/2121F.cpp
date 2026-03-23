/******************************************************************************
Link: https://codeforces.com/contest/2121/problem/F
Code: 2121F
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-17-21.04.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, s, x;
    cin >> n >> s >> x;

    vector<int> a(n + 1), pre(n + 1);
    pre[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    map<int, int> mp;
    int l = 1;

    int res = 0;
    for(int r = 1; r <= n; ++r){
        if(a[r] > x){
            mp.clear();
            l = r + 1;
        }
        else if(a[r] == x){
            for(int i = l; i <= r; ++i){
                mp[pre[i - 1] + s]++;
            }
            l = r + 1;
        }

        if(mp.count(pre[r])){
            res += mp[pre[r]];
        }
    }

    cout << res << '\n';
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
