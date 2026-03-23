#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXQ=1e5;
struct operation{
    int a,b;
} operations[MAXQ+5];
int Q,K;

bool cmp(operation u,operation v){
    return u.a<v.a;
}

void solve(){
    sort(operations+1,operations+Q+1,cmp);
    int prefix=0;
    for(int i=1;i<=Q;++i){
        prefix+=operations[i].b;
        if(prefix>=K){
            cout<<operations[i].a<<'\n';
            break;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>Q;
    for(int i=1;i<=Q;++i){
        cin>>operations[i].a>>operations[i].b;
    }
    cin>>K;
    
    solve();
    return 0;
}
