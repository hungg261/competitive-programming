#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int duong=0,am=0;
    for(int i=0;i<n;++i){
        int q;cin>>q;
        if(q>0)++duong;
        else if(q<0)++am;
    }
    cout<<duong*(duong-1)/2+am*(am-1)/2;
    return 0;
}