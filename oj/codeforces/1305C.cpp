#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    if(n > m){
        cout << "0\n";
        return 0;
    }

    int ans = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            ans = 1LL * ans * llabs(arr[i] - arr[j]) % m;
        }
    }

    cout << ans << '\n';

    return 0;
}
