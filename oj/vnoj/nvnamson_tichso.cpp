#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6;
int n;
bool isZero=false;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int after=1;
    int ans=0;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;
        
        if(cur==0)isZero=true;
        int diff1=llabs(cur+1),diff2=llabs(cur-1);
        if(diff1<diff2){
            ans+=diff1;
            after*=-1;
        }
        else{
            ans+=diff2;
            // after*=1;
        }
    }
    
    if(after!=1&&!isZero){
        ans+=2;
    }
    
    cout<<ans<<'\n';
    return 0;
}
