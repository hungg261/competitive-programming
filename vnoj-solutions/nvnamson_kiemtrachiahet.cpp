#include<bits/stdc++.h>
#define int long long
using namespace std;

const int PRIME=15;
int primes[PRIME]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int solve(int n,int N){
    int ans=0;
    int high=upper_bound(primes,primes+PRIME,N)-primes;
    for(int mask=1;mask<(1<<high);++mask){
        int tich=1,cnt=0;
        for(int i=0;i<high;++i){
            if(mask&(1<<i)){
                tich*=primes[i];
                ++cnt;
            }
        }

        int total=n/tich;
        if(cnt%2==1)ans+=total;
        else ans-=total;
    }
    
    return n-ans;
}

signed main(){
    int L,R,N;
    while(cin>>L){
        if(L==-1)break;
        cin>>R>>N;
        cout<<(solve(R,N)-solve(L-1,N))<<'\n';
    }
    return 0;
}
