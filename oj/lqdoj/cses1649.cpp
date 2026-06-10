#include<bits/stdc++.h>
#define int long long
using namespace std;

struct segment_tree{
    int n;
    vector<int>nodes;

    void init(int newsize){
        n=newsize;
        nodes.resize(n*4);
    }

    void build(int id,int L,int R,vector<int>&arr){
        if(L==R){
            nodes[id]=arr[L];
            return;
        }

        int mid=(L+R)/2;
        build(id*2,L,mid,arr);
        build(id*2+1,mid+1,R,arr);

        nodes[id]=min(nodes[id*2],nodes[id*2+1]);
    }

    void update(int id,int L,int R,int pos,int x){
        if(pos<L||R<pos){
            return;
        }
        if(L==R){
            nodes[id]=x;
            return;
        }

        int mid=(L+R)/2;
        update(id*2,L,mid,pos,x);
        update(id*2+1,mid+1,R,pos,x);

        nodes[id]=min(nodes[id*2],nodes[id*2+1]);
    }

    int get(int id,int L,int R,int u,int v){
        if(v<L||R<u){
            return 1e18;
        }
        if(u<=L&&R<=v){
            return nodes[id];
        }

        int mid=(L+R)/2;
        return min(get(id*2,L,mid,u,v),get(id*2+1,mid+1,R,u,v));
    }

    void build(vector<int>&arr){
        init(arr.size());
        build(1,1,n,arr);
    }

    void update(int pos,int x){
        update(1,1,n,pos,x);
    }

    int get(int u,int v){
        return get(1,1,n,u,v);
    }
};

void query(segment_tree&segg){
    int type;
    cin>>type;

    if(type==1){
        int k,u;
        cin>>k>>u;

        segg.update(k,u);
    }
    else{
        int a,b;
        cin>>a>>b;

        cout<<segg.get(a,b)<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,t;
    cin>>n>>t;
    vector<int>arr(n+1);
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }

    segment_tree segg;
    segg.build(arr);

    while(t--){
        query(segg);
    }
    return 0;
}