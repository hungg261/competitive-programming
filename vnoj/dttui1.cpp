#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=40,MAXMID=(MAXN+1)/2;
struct bag{
    int weight,value;
} arr[MAXN],storeA[1<<MAXMID],storeB[1<<MAXMID];
int n,w,lenA=0,lenB=0;
int leftmax[1<<MAXMID];

bool op(bag&u,bag&v){
    if(u.weight==v.weight)return u.value<v.value;
    return u.weight<v.weight;
}

void generate(bag a[],int n,bag storage[],int&len){
    for(int mask=0;mask<(1<<n);++mask){
        int sumweight=0,sumvalue=0;
        for(int i=0;i<n;++i){
            if(mask&(1<<i)){
                sumweight+=a[i].weight;
                sumvalue+=a[i].value;
            }
        }
        
        storage[len++]={sumweight,sumvalue};
    }
}

int find_lower(int idx,int target){
    int l=0,h=lenB-1,res=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(storeA[idx].weight+storeB[mid].weight<=target){
            l=mid+1;
            res=mid;
        }
        else h=mid-1;
    }
    return res;
}

void solve(){
    int mid=n/2;
    bag space1[mid],space2[n-mid];
    for(int i=0;i<mid;++i){
        space1[i]=arr[i];
    }
    for(int i=mid;i<n;++i){
        space2[i-mid]=arr[i];
    }
    
    generate(space1,mid,storeA,lenA);
    generate(space2,n-mid,storeB,lenB);
    
    // cout<<lenA<<'\n';
    // for(int i=0;i<lenA;++i){
    //     cout<<storeA[i].weight<<' '<<storeA[i].value<<'\n';
    // }
    
    sort(storeB,storeB+lenB,op);
    leftmax[0]=storeB[0].value;
    for(int i=1;i<lenB;++i){
        leftmax[i]=max(leftmax[i-1],storeB[i].value);
    }
    
    int ans=0;
    for(int i=0;i<lenA;++i){
        int idx=find_lower(i,w);
        if(idx==-1)continue;
        
        ans=max(ans,storeA[i].value+leftmax[idx]);
    }
    
    // cout<<"--------------\n";
    // cout<<lenB<<'\n';
    // for(int i=0;i<lenB;++i){
    //     cout<<storeB[i].weight<<' '<<storeB[i].value<<'\n';
    // }
    
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>w;
    for(int i=0;i<n;++i){
        cin>>arr[i].weight>>arr[i].value;
    }
    
    solve();
    return 0;
}
