#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5;
int BIT[MAXN+1],n;

void update(int idx,int x){
    while(idx<=n){
        BIT[idx]+=x;
        idx+=idx&(-idx);
    }
}

int get(int idx){
    int sum=0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=idx&(-idx);
    }
    return sum;
}

void query(){
    int type;
    cin>>type;

    if(type==1){
        int p,x;
        cin>>p>>x;

        update(p,x);
    }
    else{
        int u,v;
        cin>>u>>v;

        cout<<get(v)-get(u-1)<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int Q;
    cin>>n>>Q;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;

        update(i,cur);
    }

    while(Q--){
        query();
    }
    return 0;
}