#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1002;
int S[MAX][MAX],Lres[MAX],Rres[MAX],n,m;
int store[MAX*MAX];
unordered_set<string>passed;
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

int solve(int idx,int n){
    int ans=-1;
    for(int i=1;i<=n;++i){
        int cur=(Rres[i]-Lres[i]-1)*S[idx][i];
        ans=max(ans,cur);
        
        string key=to_string(idx)+'.'+to_string(min(S[idx][Lres[i]+1],S[idx][Rres[i]-1]))+'.'+to_string(Lres[i]+1)+'.'+to_string(Rres[i]-1);
        // cout<<i<<' '<<cur<<' '<<key<<'\n';
        if(!passed.count(key)){
            passed.insert(key);
            ++store[cur];
        }
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    
    for(int j=1;j<=m;++j){
        S[1][j]=!a[1][j];
    }
    compute(S[1],m);
    int res=solve(1,m);
    for(int i=2;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j])S[i][j]=0;
            else S[i][j]=S[i-1][j]+1;
        }
        compute(S[i],m);
        res=max(res,solve(i,m));
    }
    
    if(res==0)store[res]=0;
    cout<<res<<' '<<store[res]<<'\n';
    return 0;
}
