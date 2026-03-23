#include<bits/stdc++.h>
#define int long long
using namespace std;

int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}

int solve(int n,int x,int y){
    return n/lcm(x,y);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m,n,x,y;
    cin>>m>>n>>x>>y;
    
    cout<<solve(n,x,y)-solve(m-1,x,y)<<'\n';
    return 0;
}
