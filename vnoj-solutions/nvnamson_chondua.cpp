#include<bits/stdc++.h>
#define int long long
using namespace std;

// practice custom hash function
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r){
    return l+rng()%(r-l+1);
}

const int BASE1=llabs(rng())|1,BASE2=llabs(rng())|1,BASE3=llabs(rng())|1;
struct CustomHash{
    int operator()(int x) const{
        x^=x>>16;
        x*=BASE1;
        x^=x>>16;
        x*=BASE2;
        x^=x>>16;
        x*=BASE3;
        x^=x>>16;
        
        return x;
    }
};

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CHONDUA.INP","r",stdin);
    freopen("CHONDUA.OUT","w",stdout);
    int n;
    cin>>n;
    
    vector<int>a(n),b(n);
    for(int&ele:a){
        cin>>ele;
    }
    for(int&ele:b){
        cin>>ele;
    }
    
    unordered_map<int,int,CustomHash>X,Y;
    for(int ele:a){
        ++X[ele];
    }
    for(int ele:b){
        ++Y[ele];
    }
    
    int ans=0;
    for(auto p:X){
        ans+=min(p.second,Y[p.first]);
    }
    
    cout<<ans<<endl;
    return 0;
}
