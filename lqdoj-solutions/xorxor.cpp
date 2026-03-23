#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=101;
int P[MAX]={};
signed main(){
    int n;cin>>n;
    cin>>P[0];
    for(int i=1,q;i<n;++i){
        cin>>q;
        P[i]=P[i-1]^q;
    }

    int ans=P[0];
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            int cur;
            if(i==0)
                cur=P[j];
            else cur=P[j]^P[i-1];
            ans=max(ans,cur);
        }
    }
    cout<<ans;
    return 0;
}