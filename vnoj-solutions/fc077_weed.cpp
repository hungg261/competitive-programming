#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    
    int maximum=-1e9,minimum=1e9;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;
        
        maximum=max(maximum,cur);
        minimum=min(minimum,cur);
    }
    
    cout<<maximum-minimum<<'\n';
    return 0;
}
