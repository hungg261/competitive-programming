#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    
    if(n%3==0){
        cout<<(n/3)*7<<'\n';
    }
    else if(n%3==1){
        cout<<((n-4)/3)*7+4<<'\n';
    }
    else cout<<((n-2)/3)*7+1<<'\n';
    
    return 0;
}
