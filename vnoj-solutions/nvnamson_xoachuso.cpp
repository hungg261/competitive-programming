#include<bits/stdc++.h>
using namespace std;

void operate(string&n){
    int m=n.size();
    for(int i=0;i+1<m;++i){
        if(n[i]<n[i+1]){
            n.erase(begin(n)+i);
            return;
        }
    }
    n.pop_back();
}

signed main(){
    string n;
    int k;
    cin>>n>>k;
    
    while(k--){
        operate(n);
    }
    cout<<n<<'\n';
    return 0;
}
