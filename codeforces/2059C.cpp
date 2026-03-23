#include<bits/stdc++.h>
//#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> arr[i][j];
        }
    }

    vector<int> suf(n, 0);
    for(int i = 0; i < n; ++i){
        for(int j = n - 1; j >= 0; --j){
            if(arr[i][j] != 1) break;
            suf[i]++;
        }
    }

    sort(begin(suf), end(suf));
    int best = 0;
    for(int i = 0; i < n; ++i){
        if(suf[i] >= best){
            ++best;
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
