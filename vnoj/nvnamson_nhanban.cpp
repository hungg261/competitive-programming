#include<bits/stdc++.h>
#define int long long
using namespace std;

string base;
int a,b;
int get_closet(int start,int len,int remain,int step){
    if(len==1)return start;
    
    for(int i=start;;i+=step){
        if(i%len==remain){
            return i;
        }
    }
    return -1;
}

void solve(){
    int len=base.size();
    int low=get_closet(a,len,1,1),
        high=get_closet(b,len,0,-1);
    
    int digit_sum=0;
    for(int i=0;i<len;++i){
        digit_sum+=base[i]-'0';
    }
    int ans=digit_sum*((high-low+1)/len);
    int passed_low=(low-1)/len,passed_high=high/len+1;

    if(passed_low%2==0){
        reverse(begin(base),end(base));
    }
    for(int i=a;i<low;++i){
        ans+=base[(i-1)%len]-'0';
    }
    if(passed_low%2==0){
        reverse(begin(base),end(base));
    }
    
    if(passed_high%2==0){
        reverse(begin(base),end(base));
    }
    for(int i=b;i>high;--i){
        ans+=base[(i-1)%len]-'0';
    }
    if(passed_high%2==0){
        reverse(begin(base),end(base));
    }
    
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>base>>a>>b;
    
    solve();
    return 0;
}
