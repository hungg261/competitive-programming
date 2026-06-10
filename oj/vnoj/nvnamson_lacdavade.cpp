#include<bits/stdc++.h>
using namespace std;

bool query(int n){
    return n%10!=0;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        cout<<(query(n)?"SIUU\n":"BOBO\n");
    }
    return 0;
}
