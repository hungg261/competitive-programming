#include<bits/stdc++.h>
using namespace std;

signed main(){
    unordered_set<int>A;
    int n;cin>>n;
    for(int q;n--;){
        cin>>q;
        A.insert(q);
    }
    cout<<A.size();
    return 0;
}