#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

int sumdiv(int l,int r,int d){
    ++l,--r;
    
    l+=(d-l%d)%d;
    r-=r%d;
    
    if(r<l)return 0;
    return (l+r)*((r-l)/d+1)/2;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b;
    cin>>a>>b;
    
    cout<<sumdiv(a,b,2)-sumdiv(a,b,6)<<'\n';
    return 0;
}
