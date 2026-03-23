/******************************************************************************
Link: https://codeforces.com/contest/1753/problem/B
Code: 1753B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-09-17.41.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> a(n + 1), cnt(x + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int k = 1; k < x; ++k){
        while(cnt[k] >= (k + 1)){
            cnt[k] -= k + 1;
            cnt[k + 1]++;
        }
    }

    for(int k = 1; k < x; ++k){
        if(cnt[k] != 0){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}
