#include<bits/stdc++.h>
#define int long long
using namespace std;

int a,b,n;

int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}

int check(int mid){
    return mid/a+mid/b-mid/lcm(a,b);
}

int tknp(){
    int l=2,h=1e18,k=2;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)>=n)
            k=mid,h=mid-1;
        else l=mid+1;
    }
    return k;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>a>>b>>n;
        cout<<tknp()<<'\n';
    }

    return 0;
}