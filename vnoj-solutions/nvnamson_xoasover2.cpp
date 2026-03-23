#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k;
int get_row(int target,int x){
    int VT=target-((1LL<<(x-1))+1),
        VP=1LL<<x;
    
    if(VT%VP==0)return VT/VP;
    return -1;
}

int get_closet(int target,int x){
    int VT=target-((1LL<<(x-1))+1),
        VP=1LL<<x;
    
    return VT/VP;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    int ans=0,row;
    for(int x=1;x<=7;++x){
        row=get_row(k,x);
        if(row==-1){
            ans+=get_closet(n,x)+1;
        }
        else{
            ans+=row+1;
            break;
        }
    }
    
    cout<<ans<<'\n';
    return 0;
}
