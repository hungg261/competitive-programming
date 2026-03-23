/******************************************************************************
Link: https://codeforces.com/contest/1513/problem/D
Code: 1513D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-06-20.16.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, p;
    cin >> n >> p;

    vector<int> arr(n + 1);
    vector<pair<int, int>> temp(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        temp[i].first = arr[i];
        temp[i].second = i;
    }
    sort(begin(temp) + 1, end(temp));

    vector<bool> mark(n + 1, false);
    int res = 0, comp = 0;
    for(int i = 1; i <= n; ++i){
        int val, idx; tie(val, idx) = temp[i];
        if(mark[idx]) continue;

        int l = idx - 1, r = idx + 1;
        for(int g = val; r <= n; ++r){
            g = __gcd(g, arr[r]);
            if(g < val) break;
            if(mark[r]){
                ++r;
                --comp;
                break;
            }
            mark[r] = true;
        } --r;
        for(int g = val; l >= 1; --l){
            g = __gcd(g, arr[l]);
            if(g < val) break;
            if(mark[l]){
                --l;
                --comp;
                break;
            }
            mark[l] = true;
        } ++l;

        res += min(p, val) * (r - l);
        ++comp;
    }
    res += p * (comp - 1);

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
