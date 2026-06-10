#include<bits/stdc++.h>
#define int long long
using namespace std;

template<typename _T> int getsize(const _T&vec){
    return vec.size();
}

int to_int(string value){
    int res=0;
    for(char digit:value){
        (res*=10)+=digit-'0';
    }
    return res;
}

struct bigint{
    vector<int>a;
    const int BASE=1e9;
    const int WIDTH=9;
    
    bigint(){}
    bigint(int x){
        while(x>0){
            a.push_back(x%BASE);
            x/=BASE;
        }
    }
    
    void trim(){
        while(!a.empty()&&a.back()==0){
            a.pop_back();
        }
    }
    
    bigint operator+(const bigint&b){
        bigint res;
        int n=max(getsize(a),getsize(b.a)),carry=0;
        for(int i=0;i<n||carry;++i){
            int cur=(i<getsize(a)?a[i]:0)+(i<getsize(b.a)?b.a[i]:0)+carry;
            res.a.push_back(cur%BASE);
            carry=cur/BASE;
        }
        
        return res;
    }
    
    void input(){
        string num;
        cin>>num;
        
        a.clear();
        for(int i=getsize(num);i>0;i-=WIDTH){
            int start=max(0LL,i-WIDTH);
            a.push_back(to_int(num.substr(start,i-start)));
        }
    }
    
    void output(){
        if(a.empty()){
            cout<<"0";
            return;
        }
        
        cout<<a.back();
        for(int i=getsize(a)-2;i>=0;--i){
            cout<<setw(WIDTH)<<setfill('0')<<a[i];
        }
    }
    
    void debug(){
        for(int ele:a){
            cerr<<ele<<' ';
        }
        cerr<<'\n';
    }
};

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    bigint A,B;
    A.input();
    B.input();
    
    (A+B).output();
    return 0;
}
