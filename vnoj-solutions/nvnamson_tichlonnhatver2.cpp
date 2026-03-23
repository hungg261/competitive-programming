#include<iostream>
using namespace std;

short lonnhat1,lonnhat2,lonnhat3,nhonhat1,nhonhat2;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("TICHMAX.INP","r",stdin);
    freopen("TICHMAX.OUT","w",stdout);
    nhonhat1=nhonhat2=30001;
    lonnhat1=lonnhat2=lonnhat3=-30001;
    
    short cur;
    cin>>cur;
    while(cin>>cur){
        if(cur>lonnhat3){
            lonnhat1=lonnhat2;
            lonnhat2=lonnhat3;
            lonnhat3=cur;
        }
        else if(cur>lonnhat2){
            lonnhat1=lonnhat2;
            lonnhat2=cur;
        }
        else if(cur>lonnhat1)lonnhat1=cur;
        
        if(cur<nhonhat2){
            nhonhat1=nhonhat2;
            nhonhat2=cur;
        }
        else if(cur<nhonhat1)nhonhat1=cur;
    }
    
    cout<<max(1LL*nhonhat1*nhonhat2*lonnhat3,1LL*lonnhat1*lonnhat2*lonnhat3)<<'\n';
    return 0;
}
