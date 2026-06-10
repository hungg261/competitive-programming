#include<bits/stdc++.h>
#define int long long
#define right sussy
using namespace std;

const int MAXN=1e6;
int a[MAXN+1],n,m,prefix[MAXN+1];

int subtract=0;
int tknp(int target){
    int l=1,h=n,res=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(a[mid]-subtract>=target){
            res=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    return res;
}

int right;
bool solve(int r){
    int ans=0;
    int idx=tknp(r);
    
    ans+=r*idx+(prefix[right]-prefix[idx]-(right-idx)*subtract);
    subtract+=r;
    right=idx;
    
    if(ans>0){
        cout<<ans<<' ';
        return true;
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    right=n;
    
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;++i){
        prefix[i]=prefix[i-1]+a[i];
    }
    
    int r;
    while(m--){
        cin>>r;
        
        if(!solve(r)){
            
        }
    }
    return 0;
}
