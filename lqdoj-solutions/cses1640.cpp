#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=2e5+1;
int n,x;
unordered_map<int,int>A;

signed main(){
    cin>>n>>x;
    bool f=0;
    for(int i=0,q;i<n;++i){
        cin>>q;
        if(A.count(x-q)){
            cout<<A[x-q]<<' '<<i+1;
            f=1;
            break;
        }
        A[q]=i+1;
    }
    if(!f)cout<<"IMPOSSIBLE";
    return 0;
}