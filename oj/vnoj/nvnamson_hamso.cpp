#include<bits/stdc++.h>
#define int long long
using namespace std;

int equation(int mid){
    return mid*mid*mid-2*mid+5;
}

int tknp(int target){
    int l=1,h=1000000;
    while(l<=h){
        int mid=(l+h)/2,value=equation(mid);
        if(value==target){
            return mid;
        }
        else if(value>target)
            h=mid-1;
        else l=mid+1;
    }
    return -1;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    
    while(t--){
        int K;
        cin>>K;
        
        cout<<tknp(K)<<'\n';
    }
    return 0;
}
