#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e6+1;
int A[MAX],k=0,n;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    while(n>9){
        n-=9;
        A[k++]=9;
    }
    A[k]=n;

    for(int i=k;i>=0;--i)cout<<A[i];
    return 0;
}