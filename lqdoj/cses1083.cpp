#include<bits/stdc++.h>
using namespace std;

const int MAX=2e5+1;
int A[MAX],n;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0,q;i<n-1;++i){
        cin>>q;
        ++A[q];
    }

    int i=0;
    while(A[++i]>0);
    cout<<i;
    return 0;
}