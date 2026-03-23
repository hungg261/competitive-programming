#include<bits/stdc++.h>
using namespace std;

const int MAX=50;
int n,m;
string row[MAX],col[MAX];

bool KMP(const string&s,string t){
    int target=t.size();
    t=t+'#'+s;
    vector<int>pi((int)t.size());
    pi[0]=0;
    for(int i=1;i<(int)t.size();++i){
        int j=pi[i-1];
        while(j>0&&t[i]!=t[j]){
            j=pi[j-1];
        }
        
        if(t[i]==t[j]){
            ++j;
        }
        pi[i]=j;
        
        if(j==target){
            return true;
        }
    }
    
    return false;
}

bool check(const string&s){
    string rev_s=s;
    reverse(begin(rev_s),end(rev_s));
    for(int i=0;i<n;++i){
        if(KMP(row[i],s)||KMP(row[i],rev_s)){
            return true;
        }
    }
    for(int j=0;j<m;++j){
        if(KMP(col[j],s)||KMP(col[j],rev_s)){
            return true;
        }
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>row[i];
    }
    for(int j=0;j<m;++j){
        for(int i=0;i<n;++i){
            col[j]+=row[i][j];
        }
    }
    
    int q;
    cin>>q;
    
    while(q--){
        string cur;
        cin>>cur;
        
        cout<<(check(cur)?"YES\n":"NO\n");
    }
    return 0;
}
