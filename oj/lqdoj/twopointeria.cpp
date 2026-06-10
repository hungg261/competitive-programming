#include<bits/stdc++.h>
using namespace std;

const int MAX=2e5+1;
int A[MAX];
signed main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n+m;++i)cin>>A[i];
    sort(A,A+n+m);

    for(int i=0;i<n+m;++i)cout<<A[i]<<' ';
    return 0;
}