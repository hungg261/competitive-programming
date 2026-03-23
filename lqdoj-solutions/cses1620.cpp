#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=2e5+1;
int n,k,a[MAX];

bool solve(int mid){
    int r=0;
    for(int i=0;i<n;i++){
        r+=mid/a[i];
        if(r>=k)return true;
    }
    return false;
}

int tknp(){
    int l=1,h=1e18+1,r=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(solve(mid))
            r=mid,h=mid-1;
        else l=mid+1;
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    cout<<tknp()<<'\n';
    return 0;
}