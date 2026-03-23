#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        cout<<__builtin_parityll(n)<<'\n';
    }
    
    return 0;
}
