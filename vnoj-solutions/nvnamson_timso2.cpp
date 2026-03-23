#include<bits/stdc++.h>
#define int long long
using namespace std;

bool all_equal(const vector<int>&v,int target){
    for(const int&q:v){
        if(q!=target)return false;
    }
    return true;
}

void solve(int n){
    int ans=1;
    vector<int>mu;
    
    int c=0;
    while(n%2==0){
        n/=2;
        ++c;
    }
    if(c>0){
        mu.push_back(c);
        ans*=2;
    }
    
    for(int i=3;i*i<=n;i+=2){
        c=0;
        while(n%i==0){
            n/=i;
            ++c;
        }
        if(c>0){
            mu.push_back(c);
            ans*=i;
        }
    }
    if(n>1){
        mu.push_back(1);
        ans*=n;
    }
    
    int cnt=(int)ceil(log2(*max_element(begin(mu),end(mu))));
    if(!all_equal(mu,1<<cnt))++cnt;
    
    cout<<ans<<' '<<cnt<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    solve(n);
    return 0;
}
