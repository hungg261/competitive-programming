#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    set<int> cnt;

    cin >> n;

    int prv;
    for(int i = 1; i <= n; ++i){
        cin >> prv;

        cnt.insert(prv);
    }

    int cur = cnt.size();
    while(prv != cur){
        cnt.insert(cur);
        prv = cur;
        cur = cnt.size();
    }

    cout << cnt.size() << '\n';
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
