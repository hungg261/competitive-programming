#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=32,MAXMID=(MAXN+1)/2;
int arr[MAXN],n;
int storeA[1<<MAXMID],storeB[1<<MAXMID];
int lenA=0,lenB=0;
int total=0;

void generate(int space[],int n,int storage[],int&len){
    for(int mask=0;mask<(1<<n);++mask){
        int sum=0;
        for(int i=0;i<n;++i){
            if(mask&(1<<i)){
                sum+=space[i];
            }
        }
        storage[len++]=sum;
    }
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
    
    generate(space1,mid,storeA,lenA);
    generate(space2,n-mid,storeB,lenB);
    sort(storeB,storeB+lenB);
    // for(int i=0;i<lenA;++i){
    //     cout<<storeA[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i=0;i<lenB;++i){
    //     cout<<storeB[i]<<' ';
    // }
    // cout<<'\n';
    
    int target=total/2;
    int mindiff=1e18;
    unordered_map<int,int>cntways;
    for(int i=0;i<lenA;++i){
        if(storeA[i]>target)continue;
        
        int value=*(upper_bound(storeB,storeB+lenB,target-storeA[i])-1);
        int cur=storeA[i]+value;
        
        int diff=total-cur*2;
        mindiff=min(mindiff,diff);
        // cerr<<total<<' '<<target<<' '<<cur<<' '<<diff<<' '<<storeA[i]<<' '<<value<<' '<<(upper_bound(storeB,storeB+lenB,value)-lower_bound(storeB,storeB+lenB,value))<<'\n';
        
        cntways[diff]+=upper_bound(storeB,storeB+lenB,value)-lower_bound(storeB,storeB+lenB,value);
    }
    
    cout<<mindiff<<' '<<(mindiff==0?cntways[mindiff]/2:cntways[mindiff])<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
        total+=arr[i];
    }
    
    solve();
    return 0;
}
