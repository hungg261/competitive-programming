#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    map<int, int> freq;
    for(int i = 0; i < n * 2; ++i){
        int x; cin >> x;
        freq[x]++;
    }

    int ans = 0;
    int imb = 0, odd = 0;
    for(const auto& p: freq){
        if(p.second & 1){
            ans++;
            ++odd;
        }
        else{
            if(p.second % 4 == 0){
                ++imb;
            }
            ans += 2;
        }
    }

    if(odd == 0 && imb % 2 == 1){
        ans -= 2;
    }

    cout << ans << '\n';
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
