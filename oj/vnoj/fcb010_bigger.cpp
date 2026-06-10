#include<bits/stdc++.h>
using namespace std;

int power(int a,int b){
    int res=1;
    while(b--)res*=a;
    
    return res;
}

signed main(){
    long double A,B;
    cin>>A>>B;
    
    int l=0,h=10,res=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(A*power(3,mid)>B*power(2,mid)){
            res=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    
    cout<<res<<'\n';
    return 0;
}
