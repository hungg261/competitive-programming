#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
// #pragma GCC target("avx2")
using namespace std;

int get_count(int sum){
    int res=0;
    for(int a=1;a<=sum/2;++a){
        int b=sum-a;
        
        if(__gcd(a,b)==1){
            ++res;
        }
    }
    return res;
}

int get_res(int d,int u){
    return d*(u+1);
}

int solve(int n){
    int ans=0;
    vector<int>uoc;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            uoc.push_back(i);
            if(i*i!=n){
                uoc.push_back(n/i);
            }
        }
    }
    
    for(int i:uoc){
        ans+=get_count(n/i+1);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    
    cout<<solve(n)<<'\n';
    return 0;
}
