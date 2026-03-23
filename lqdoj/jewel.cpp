#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("jewel.INP","r",stdin);freopen("jewel.OUT","w",stdout);
    int n,c=0;cin>>n;
    unordered_map<int,bool>R;
    for(int i=0,q;i<n&&cin>>q;++i){
        if(!R.count(q-1))++c;
        R[q]=1;
    }
    cout<<c;
    return 0;
}