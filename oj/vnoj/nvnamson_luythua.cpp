#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,c=0;cin>>n;
    while(n--){
        int s;cin>>s;
        c+=pow(s/10,s%10);
    }
    cout<<c;
    return 0;
}
