#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e6+1;
int A[MAX],n,k;

int tknp(int l,int val){
    int h=n-1,r=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(A[mid]<=k-val)
            r=mid,l=mid+1;
        else h=mid-1;
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>A[i];
    sort(A,A+n);

    int ans=0;
    for(int i=0;i<n&&A[i]<k;++i){
        int pos=tknp(i+1,A[i]);
        if(pos>=0)ans+=pos-i; 
    }
    cout<<ans;
    return 0;
}