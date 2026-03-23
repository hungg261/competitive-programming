#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1002;
int S[MAX][MAX],Lres[MAX],Rres[MAX],n,m;
bool a[MAX][MAX];

void compute(int A[],int n){
    stack<int>L;
    for(int i=1;i<=n;++i){
        while(!L.empty()&&A[i]<=A[L.top()])L.pop();
        if(L.empty())Lres[i]=0;
        else Lres[i]=L.top();

        L.push(i);
    }
    
    stack<int>R;
    for(int i=n;i>=1;--i){
        while(!R.empty()&&A[i]<=A[R.top()])R.pop();
        if(R.empty())Rres[i]=n+1;
        else Rres[i]=R.top();
        
        R.push(i);
    }
}

int solve(int A[],int n){
    int ans=0;
    for(int i=1;i<=n;++i){
        ans=max(ans,(Rres[i]-Lres[i]-1)*A[i]);
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
            a[i][j]=!a[i][j];
        }
    }
    
    for(int j=1;j<=m;++j){
        S[1][j]=!a[1][j];
    }
    compute(S[1],m);
    int res=solve(S[1],m);
    for(int i=2;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j])S[i][j]=0;
            else S[i][j]=S[i-1][j]+1;
        }
        compute(S[i],m);
        res=max(res,solve(S[i],m));
    }
    cout<<res;
    return 0;
}
