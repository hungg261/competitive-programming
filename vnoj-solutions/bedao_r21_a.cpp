#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXVAL=31623;
bool not_prime[MAXVAL+1];
vector<int>primes;

void compute(){
    not_prime[0]=not_prime[1]=true;
    for(int i=2;i*i<=MAXVAL;++i){
        for(int j=i*i;j<=MAXVAL;j+=i){
            not_prime[j]=true;
        }
    }
    
    for(int i=1;i<=MAXVAL;++i){
        if(!not_prime[i]){
            primes.push_back(i);
        }
    }
}

bool is_prime(int n){
    for(int i=2;i*i<=n;++i){
        if(n%i==0)return false;
    }
    return n>1;
}

int sqrt8(int n){
    int l=1,h=178;
    while(l<=h){
        int mid=(l+h)/2,value=mid*mid*mid*mid*mid*mid*mid*mid;
        if(value==n){
            return mid;
        }
        else if(value>n){
            h=mid-1;
        }
        else l=mid+1;
    }
    return 0;
}

int sqrt2(int n){
    int l=1,h=1e9+1;
    while(l<=h){
        int mid=(l+h)/2,value=mid*mid;
        if(value==n){
            return mid;
        }
        else if(value>n){
            h=mid-1;
        }
        else l=mid+1;
    }
    return -1;
}

void query(int n){
    if(!not_prime[sqrt8(n)]){
        cout<<"YES\n";
        return;
    }
    
    int root=sqrt2(n);
    if(root==-1){
        cout<<"NO\n";
        return;
    }
    
    for(int prime:primes){
        if(prime*prime>=root){
            break;
        }
        
        if(root%prime==0){
            if(is_prime(root/prime)){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    compute();
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        query(n);
    }
    return 0;
}
