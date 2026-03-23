#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5;
int n,a[MAXN+5],nodes[MAXN*4+5];

void build(int id,int l,int r){
    if(l==r){
        nodes[id]=a[l];
        return;
    }
    
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    nodes[id]=nodes[id*2]+nodes[id*2+1];
}

void update(int id,int l,int r,int x,int y){
    if(r<x||x<l){
        return;
    }
    
    if(l==r){
        nodes[id]=y;
        return;
    }
    
    int mid=(l+r)/2;
    update(id*2,l,mid,x,y);
    update(id*2+1,mid+1,r,x,y);
    nodes[id]=nodes[id*2]+nodes[id*2+1];
}

int get(int id,int l,int r,int u,int v){
    if(r<u||v<l){
        return 0;
    }
    
    if(u<=l&&r<=v){
        return nodes[id];
    }
    
    int mid=(l+r)/2;
    int range1=get(id*2,l,mid,u,v),
        range2=get(id*2+1,mid+1,r,u,v);
    return range1+range2;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        // cin>>a[i];
        a[i]=0;
    }
    build(1,1,n);
    
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        
        if(type==1){
            int x,y;
            cin>>x>>y;
            
            update(1,1,n,x,y);
        }
        else{
            int l,r;
            cin>>l>>r;
            
            cout<<get(1,1,n,l,r)<<'\n';
        }
    }
    
    return 0;
}
