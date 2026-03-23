#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1e6+1;
int c=0,Q[MAX];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("lis.INP","r",stdin);freopen("lis.OUT","w",stdout);
    int n;cin>>n;
    int A[n];inp(A,n);

    Q[0]=A[0];
    for(int i=0;i<n;++i){
        if(A[i]>Q[c]){
            Q[++c]=A[i];
        }
        else{
            int idx=lower_bound(Q,Q+c,A[i])-Q;
            Q[idx]=A[i];
        }
    }
    cout<<c+1;
    return 0;
}