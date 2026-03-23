#include<bits/stdc++.h>
using namespace std;

bool check(long long n){
    int check=0;
    while(n>0){
        int bit=1<<(n%10);
        if(check&bit){
            return false;
        }
        else check|=bit;
        
        n/=10;
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    
    for(long long x=n+1;;++x){
        if(check(x)){
            cout<<x<<'\n';
            break;
        }
    }
    return 0;
}
