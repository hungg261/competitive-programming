/******************************************************************************
Link: https://codeforces.com/contest/1349/problem/B
Code: 1349B
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-05-10.52.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
int n;
int arr[MAXN + 5];

bool check(int x) {
    vector<int> P(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        P[i] = P[i - 1] + (arr[i] >= x ? 1 : -1);
    }

    int min_pre = 1e9;
    for(int i = 2; i <= n; ++i){
        min_pre = min(min_pre, P[i - 2]);

        if(P[i] - min_pre > 0) return true;
    }
    return false;
}

void solve(){
    int k;
    cin >> n >> k;

    bool is_k = false;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        if(arr[i] == k) is_k = true;
    }

    if(n == 1 && is_k){
        cout << "yes\n";
        return;
    }

    bool ok1 = check(k), ok2 = check(k + 1);
    cout << (is_k && ok1 && ok1 >= ok2 ? "yes\n" : "no\n");
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
