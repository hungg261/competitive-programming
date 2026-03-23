#include<bits/stdc++.h>
#define int long long
#define umap unordered_map
using namespace std;

const int MAX=37;
int A[MAX],n,m,s;

auto counter(int l,int h){
    umap<int,umap<int,int>>Q;
    int n=h-l+1;
    for(int i=0;i<(1<<n);++i){
        int sum=0,sz=0;
        for(int j=0;j<n;++j){
            if(i&(1<<j)){
                sum+=A[l+j];
                ++sz;
            }
        }
        ++Q[sz][sum];
    }
    return Q;
}

int solve(){
    auto B=counter(0,n/2-1);
    auto E=counter(n/2,n-1);

    int count=0;
    for(auto p:B){
        int sz=p.first,_size=m-sz;
        auto sum=p.second;
        for(auto&q:sum){
            int sum1=q.first,cnt1=q.second,_sum=s-sum1;
            if(E.count(_size)&&E[_size].count(_sum))
                count+=cnt1*E[_size][_sum];
        }
    }
    return count;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(int i=0;i<n;++i)cin>>A[i];

    cout<<solve();
    return 0;
}