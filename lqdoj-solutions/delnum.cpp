/******************************************************************************
Link: DIGIT
Code: DIGIT
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-14-16.47.04
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
#define int long long
using namespace std;

string s,r="";
int k=0,n;
stack<char>A;

void clean(){
    while(!A.empty()&&k>0){
        A.pop();
        --k;
    }
}

void solve(){
    for(char q:s){
        while(!A.empty()&&A.top()<q&&k>0){
            A.pop();
            --k;
        }
        A.push(q);
    }
    clean();
}

void out(){
    while(!A.empty()){
        r+=A.top();
        A.pop();
    }
    reverse(it(r));
    cout<<r.substr(0,n-k);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("DIGIT.INP","r",stdin);freopen("DIGIT.OUT","w",stdout);
    cin>>s>>k;
    n=s.size();

    solve();
    out();
    return 0;
}