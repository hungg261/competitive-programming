#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
int target,n,prefix,freq[3];
string s;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    n=s.size();
    
    target=(accumulate(begin(s),end(s),0)-'0'*n)%3;
    ++freq[target];
    long long ans=target==0;
    for(int i=0;i<n;++i){
        int digit=s[i]-'0';
        
        prefix=(prefix+digit)%3;
        // cout<<i+1<<' '<<freq[prefix]<<'\n';
        ans+=freq[prefix];
        ++freq[(prefix+target)%3];
    }
    cout<<ans-1<<'\n';
    return 0;
}
