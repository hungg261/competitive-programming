#include<bits/stdc++.h>
#define int long long
using namespace std;

int a1,b1,a2,b2;
int inv(int a,int b){
    return a>1?b-inv(b%a,a)*b/a:1;
}

int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}

void solve(){
    if(b1>b2){
        swap(a1,a2);
        swap(b1,b2);
    }
    
    int d=__gcd(a1,a2);
    int star=(b2-b1)%a2;
    
    int inverse=inv(a1/d,a2/d);
    for(int x1=(star/d*inverse)%(a2/d);;x1+=a2/d){
        int x2=(a1*x1+b1-b2)/a2;
        
        if(x2>=0){
            cout<<x1<<' '<<x2<<'\n';
            break;
        }
        
        // cout<<x1<<' '<<x2<<'\n';
        // if(x1>=100)break;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a1>>b1>>a2>>b2;
    
    solve();
    return 0;
}
