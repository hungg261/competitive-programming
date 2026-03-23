#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    vector<bool> vis(n, false);
    int mask = 0, bit = 0;
    for(; bit < 32; ++bit){
        int idx = -1;
        int temp = mask;
        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;

            if((mask | arr[i]) > temp){
                temp = mask | arr[i];
                idx = i;
            }
        }

        if(idx != -1){
            mask = temp;
            cout << arr[idx] << ' ';
            vis[idx] = true;
        }
    }
    for(int i = 0; i < n; ++i){
        if(!vis[i]) cout << arr[i] << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
