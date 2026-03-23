/******************************************************************************
Link: SZERO
Code: SZERO
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-26-19.11.08
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

unordered_map<int,int>A;
const int MAX=1e5+1;
int n,r=0,P[MAX];
void solve(){
    for(int i=0;i<=n;++i)
        r+=A[P[i]],++A[P[i]];
}

void prefix_sum(){
    for(int i=0,q;i<n;++i){
        cin>>q;
        P[i+1]=P[i]+q;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("SOLVE.INP","r",stdin);freopen("SOLVE.ans","w",stdout);
    cin>>n;
    prefix_sum();
    solve();

    cout<<r;
    return 0;
}