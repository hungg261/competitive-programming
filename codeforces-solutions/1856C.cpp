/******************************************************************************
Link: https://codeforces.com/contest/1856/problem/C
Code: 1856C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-10-11.50.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e15;

int f(int i, int h, const vector<int>& arr){
    if(i >= (int)arr.size()) return INF;
    if(h <= arr[i]) return 0;
    return h - arr[i] + f(i + 1, h - 1, arr);
}

bool check(int mid, int k, const vector<int>& arr){
    for(int i = 0; i < (int)arr.size(); ++i){
        if(f(i, mid, arr) <= k){
            return true;
        }
    }
    return false;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    int l = 0, r = 1e9, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid, k, arr)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
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
