#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXSTORAGE=59049;
int n,M,arr[20];
int Left[MAXSTORAGE],lenL=0,Right[MAXSTORAGE],lenR=0;

void generate(int idx,int space[],int n,int sum,int storage[],int&len){
    if(idx>=n){
        storage[len++]=sum;
        return;
    }
    
    generate(idx+1,space,n,sum+space[idx],storage,len);
    generate(idx+1,space,n,sum-space[idx],storage,len);
    generate(idx+1,space,n,sum,storage,len);
}

void solve(){
    int mid=n/2;
    int space1[mid],space2[n-mid];
    
    for(int i=0;i<mid;++i){
        space1[i]=arr[i];
    }
    for(int i=mid;i<n;++i){
        space2[i-mid]=arr[i];
    }
    
    generate(0,space1,mid,0,Left,lenL);
    generate(0,space2,n-mid,0,Right,lenR);
    sort(Right,Right+lenR);
    
    int ans=0;
    for(int i=0;i<lenL;++i){
        int target=M-Left[i];
        ans+=upper_bound(Right,Right+lenR,target)-lower_bound(Right,Right+lenR,target);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>M;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    
    solve();
    return 0;
}
