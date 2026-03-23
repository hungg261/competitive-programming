#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    
    if(n > m || m % n != 0){
        cout << "-1\n";
        return;
    }
    
    vector<int> res;
    while(n != m){
        int multi = m / n;
        
        int g = __gcd(n, multi);
        if(g == 1){
            cout << "-1\n";
            return;
        }
        
        res.push_back(g);
        n *= g;
    }
    
    cout << (int)res.size() << ' ';
    for(int op: res){
        cout << op << ' ';
    }
    cout << '\n';
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
