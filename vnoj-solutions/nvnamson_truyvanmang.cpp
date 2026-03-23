#include<bits/stdc++.h>
using namespace std;

const int MAX=2e5;
bool a[2*MAX+5];
int n,k,p,windows[MAX+5],queries[MAX+5];
string qlist;

void compute(){
    if(k>n)return;
    
    int sz=n*2;
    int cur=0;
    for(int i=1;i<=sz;++i){
        cur+=a[i];
        if(i>=k){
            cur-=a[i-k],
            windows[i-k+1]=cur;
        }
    }
    // for(int i=1;i<=sz-k+1;++i)cerr<<windows[i]<<' ';cerr<<'\n';
    
    deque<int>dq;
    int wincnt=n-k+1;
    for(int i=1;i<=sz-k+1;++i){
        if(!dq.empty()&&i-dq.front()+1>wincnt)dq.pop_front();
        while(!dq.empty()&&windows[i]>=windows[dq.back()])dq.pop_back();
        dq.push_back(i);
        
        if(i>=wincnt){
            queries[i-wincnt+1]=windows[dq.front()];
        }
    }
    
    // for(int i=1;i<=n;++i)cout<<queries[i]<<' ';cout<<'\n';
}

void solve(){
    int cur=1;
    for(char q:qlist){
        if(q=='!'){
            cur=cur%n+1;
        }
        else{
            cout<<queries[cur]<<'\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k>>p;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i+n]=a[i];
    }
    cin>>qlist;
    
    reverse(a+1,a+n*2+1);
    compute();
    solve();
    return 0;
}
