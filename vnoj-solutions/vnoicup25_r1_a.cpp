#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    
    int n = s.size();
    if(n < 3){
        cout << "NO\n";
        return;
    }
    
    for(int i = 1; i < n - 1; ++i){
        int cntU = 0, cntI = 0;
        for(int delta = -1; delta <= 1; ++delta){
            if(s[i + delta] == 'U') ++cntU;
            else ++cntI;
        }
        
        if(cntU > 0 && cntI > 0 && (cntU >= 2*cntI || cntI >= 2*cntU)){
            cout << "YES " << i << ' ' << i + 2 << '\n';
            return;
        }
    }
    
    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}
