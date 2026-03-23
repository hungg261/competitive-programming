#include<bits/stdc++.h>
#define left sussy
#define right baka
#define int long long
using namespace std;

const int MAXN=1e5;
int a[MAXN+5],n,diff[2][MAXN+5],left[MAXN+5],right[MAXN+1];
string queries;

void compute(){
    stack<int>sta;
    for(int i=1;i<=n;++i){
        while(!sta.empty()&&a[sta.top()]<=a[i])sta.pop();
        left[i]=sta.empty()?1:sta.top();
        
        sta.push(i);
    }
    
    sta=stack<int>();
    for(int i=n;i>=1;--i){
        while(!sta.empty()&&a[sta.top()]<=a[i])sta.pop();
        right[i]=sta.empty()?n:sta.top();
        
        sta.push(i);
    }
}

void solve(){
    for(int i=1;i<=n;++i){
        ++diff[0][left[i]],
        --diff[0][i];
        
        ++diff[1][i+1],
        --diff[1][right[i]+1];
    }
    
    int prv0=0,prv1=0;
    for(int i=1;i<=n;++i){
        prv0+=diff[0][i];
        prv1+=diff[1][i];
        cout<<(queries[i-1]=='E'?prv0:prv1)<<' ';
    }
cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CAMERA.INP","r",stdin);
    freopen("CAMERA.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    cin>>queries;
    
    compute();
    solve();
    return 0;
}
