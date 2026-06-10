#include<bits/stdc++.h>
#define int long long
using namespace std;

const int pow10[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
const int counter[11]={0,1,1,10,100,1000,10000,100000,1000000,10000000,100000000};

int cnt_digit(int n){
    int res=0;
    while(n>0){
        ++res;
        n/=10;
    }
    return res;
}

bool check(int n){
    int digit_cnt=cnt_digit(n);
    return (n%10)==(n/pow10[digit_cnt-1]);
}

int get_closet(int n){
    for(int i=n;i>=1;--i){
        if(check(i))return i;
    }
    return -1;
}

int solve(int n){
    if(n==0)return 0;
    
    int closet=get_closet(n);
    int digit_cnt=cnt_digit(closet);
    int first_digit=closet/pow10[digit_cnt-1];
    int middle=digit_cnt>2?(closet/10)%pow10[digit_cnt-2]:0;
    
    int ans=0;
    for(int i=1;i<digit_cnt;++i){
        ans+=counter[i]*9;
    }
    ans+=counter[digit_cnt]*(first_digit-1);
    ans+=middle+1;
    
    // cerr<<closet<<' '<<digit_cnt<<' '<<first_digit<<' '<<middle<<' '<<counter[digit_cnt]<<'\n';
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b;
    cin>>a>>b;
    
    cout<<solve(b)-solve(a-1)<<'\n';
    return 0;
}
