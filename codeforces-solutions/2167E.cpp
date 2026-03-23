/******************************************************************************
Link: https://codeforces.com/contest/2167/problem/E
Code: 2167E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-06-11.49.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 6e9;
void solve(){
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    arr.push_back(-INF);
    arr.push_back(INF);
    sort(begin(arr), end(arr));
    n = arr.size();

    auto check = [&](int mid){
        arr[0] = -mid;
        arr[n - 1] = x + mid;

        int total = 0;
        for(int i = 1; i < n; ++i){
            total += max(0LL, arr[i] - arr[i - 1] - mid * 2 + 1);
            if(total >= k) return true;
        }

        return false;
    };

    auto build = [&](int mid){
        arr[0] = -mid;
        arr[n - 1] = x + mid;

        set<int> res;
        for(int i = 1; i < n; ++i){
            for(int j = arr[i - 1] + mid; j <= arr[i] - mid; ++j){
                res.insert(j);
                if((int)res.size() >= k) return res;
            }
        }

        return res;
    };

    int l = 0, r = x, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    for(int pos: build(res)){
        cout << pos << ' ';
    }
    cout << '\n';
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
