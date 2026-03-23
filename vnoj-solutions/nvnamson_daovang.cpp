#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=50000;
int n,k,a[MAXN];

bool check(int mid){
    int cnt=0;
    for(int i=0;i<n;){
        i=upper_bound(a,a+n,a[i]+2*mid)-a;
        ++cnt;
    }
    return cnt<=k;
}

int tknp(){
    int l=0,h=1e9,res=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)){
            h=mid-1;
            res=mid;
        }
        else l=mid+1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("DAOVANG.INP","r",stdin);
    freopen("DAOVANG.OUT","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    
    cout<<tknp()<<'\n';
    return 0;
}
