#include<bits/stdc++.h>
#define int long long
using namespace std;

int A[256]={};
signed main(){
    string s;cin>>s;
    for(char k:s){
        ++A[k];
    }

    int ans=0;
    for(int k:A){
        if(k%2==1)++ans;
    }
    cout<<max(ans-1,0LL);
    return 0;
}