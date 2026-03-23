#include<bits/stdc++.h>
#define int long long
using namespace std;

const string ngon[5]={"cai","tro","giua","ap ut","ut"};

string get_answer(int idx){
    string bantay="trai";
    if(idx>5){
        bantay="phai";
        idx=10-idx+1;
    }
    
    string ngon=::ngon[idx-1];
    return "Ngon "+ngon+" cua ban tay "+bantay;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N;
    cin>>N;
    
    int du=(N-1)%9+1,thuong=(N-1)/9+1;
    if(thuong%2==0){
        du=10-du+1;
    }
    
    cout<<get_answer(du)<<'\n';
    return 0;
}
