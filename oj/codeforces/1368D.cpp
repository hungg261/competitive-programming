#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    int cnt[30] = {};
    for(int i = 0; i < n; ++i){
        int cur;
        cin >> cur;

        for(int j = 0; j < 20; ++j){
            if(cur & (1 << j)) ++cnt[j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        int ele = 0;
        for(int j = 0; j < 20; ++j){
            if(cnt[j]){
                ele |= 1LL << j;
                --cnt[j];
            }
        }

        if(ele == 0) break;
        ans += ele * ele;
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }

    return 0;
}
