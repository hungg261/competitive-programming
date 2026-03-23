#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long
using namespace std;

const int MAXSNT=31623;
bool Q[MAXSNT+1];
int sntcnt=0,snt[3500];

void sieve(){
    Q[0]=Q[1]=true;
    for(int i=2;i*i<=MAXSNT;++i){
        if(!Q[i])for(int j=i*i;j<=MAXSNT;j+=i){
            Q[j]=true;
        }
    }
    
    for(int i=2;i<=MAXSNT;++i){
        if(!Q[i])snt[sntcnt++]=i;
    }
}

bool check3div(int n){
    int cnt=0;
    for(int i=0;i<sntcnt;++i){
        if(snt[i]*snt[i]>n)break;
        
        if(n%snt[i]==0)++cnt;
        if(cnt>=3)return true;
        
        while(n%snt[i]==0){
            n/=snt[i];
        }
    }
    if(n>1)cnt*=2;
    
    return cnt>=3;
}

int cntdigit(int n){
    return (int)log10(n)+1;
}

int build(int n,int d){
    int q=cntdigit(n),r=(d%q==0&&d/q==2?n:n/10);
    while(n>0){
        r=r*10+n%10;
        n/=10;
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b;
    cin>>a>>b;
    
    int sum=0;
    sieve();
    for(int i=1;i<=99999;++i){
        int digit_cnt=cntdigit(i),
            cur1=build(i,digit_cnt*2),
            cur2=build(i,digit_cnt*2-1);
        
        if(a<=cur1&&cur1<=b&&check3div(cur1))sum+=cur1;
        if(a<=cur2&&cur2<=b&&check3div(cur2))sum+=cur2;
        
        if(b<min(cur1,cur2))break;
    }
    cout<<sum<<'\n';
    return 0;
}
