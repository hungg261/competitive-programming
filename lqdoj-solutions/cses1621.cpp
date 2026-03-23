#include<bits/stdc++.h>
using namespace std;

int n;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    unordered_set<int>A;
    cin>>n;
    for(int i=0,q;i<n;++i){
        cin>>q;
        A.insert(q);
    }
    cout<<A.size();
    return 0;
}