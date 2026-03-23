#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
bool check(int x){
    return x*x*x==n;
}

signed main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        cout<<(check(cbrtl(n))?"YES\n":"NO\n");
    }
    return 0;
}