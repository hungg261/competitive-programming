#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;

    unordered_map<int,int>Q;
    Q[k]=1;

    int prefix=0;
    long long ans=0;
    while(n--){
        int cur;
        cin>>cur;

        prefix+=cur;
        if(Q.count(prefix)){
            ans+=Q[prefix];
        }
        ++Q[prefix+k];
    }

    cout<<ans<<'\n';
    return 0;
}