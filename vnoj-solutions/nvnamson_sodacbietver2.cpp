#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXUPPER=1e6;
bool not_prime[MAXUPPER+5];
int L,R;
vector<int>primes;

void compute(int HIGH){
    not_prime[0]=not_prime[1]=true;
    for(int i=2;i*i<=HIGH;++i){
        for(int j=i*i;j<=HIGH;j+=i){
            not_prime[j]=true;
        }
    }
    
    for(int i=1;i<=HIGH;++i){
        if(!not_prime[i]){
            primes.push_back(i-1);
        }
    }
}

int findlog(int a,int n){
    int res=0;
    while(n>=a){
        n/=a;
        ++res;
    }
    return res;
}

int solve(int n){
    int ans=0;
    for(int p:primes){
        int prime=p+1;
        
        ans+=upper_bound(begin(primes)+1,end(primes),findlog(prime,n))-(begin(primes)+1);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    compute(MAXUPPER);
    cin>>L>>R;
    
    cout<<solve(R)-solve(L-1)<<'\n';
    return 0;
}
