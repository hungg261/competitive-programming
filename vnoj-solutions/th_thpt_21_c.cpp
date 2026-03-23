#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    multiset<int, greater<int>> ms;
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;
        
        ms.insert(cur);
    }
    
    long long ans = 0;
    while(!ms.empty()){
        auto cur = ms.begin();
        
        ans += *cur;
        while(cur != ms.end()){
            ms.erase(cur);
            cur = ms.lower_bound(*cur - k);
        }
    }
    
    cout << ans << '\n';
    return 0;
}
