#include<bits/stdc++.h>
using namespace std;

struct cstack{
    vector<int>self;
    
    int get_from_top(int idx){
        return self[(int)self.size()-idx];
    }
    
    void modify_from_top(int idx,int newvalue){
        self[(int)self.size()-idx]=newvalue;
    }
    
    void modify_top(int newvalue){
        modify_from_top(1,newvalue);
    }
    
    void push(int n){
        self.push_back(n);
    }
    
    void pop(){
        self.pop_back();
    }
    
    int size(){
        return self.size();
    }
    
    int top(){
        return self.back();
    }
};

int getWeight(char k){
    switch(k){
        case 'C': return 12;
        case 'H': return 1;
        case 'O': return 16;
    }
    return 0;
}

bool is_digit(char k){
    return '0'<=k&&k<='9';
}

void solve(string s){
    s="("+s+")";
    int n=s.size();
    
    cstack sta;
    sta.push(0);
    for(int i=0;i<n;++i){
        if(s[i]=='('){
            sta.push(0);
        }
        else if(s[i]==')'){
            if(is_digit(s[i+1])){
                sta.modify_top(sta.top()*(s[i+1]-'0'));
            }
            
            int current=sta.top();
            sta.pop();
            sta.modify_top(sta.top()+current);
        }
        else{
            if(is_digit(s[i])){
                sta.modify_top(sta.top()+getWeight(s[i-1])*(s[i]-'0'-1));
            }
            else{
                sta.modify_top(sta.top()+getWeight(s[i]));
            }
        }
        
        // cerr<<s[i]<<": ";for(int ele:sta.self)cerr<<ele<<' ';cerr<<'\n';
    }
    cout<<sta.top()<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    
    solve(s);
    return 0;
}
