#include<bits/stdc++.h>
#define hash sussy
#define int long long
using namespace std;

string DecToBits(int n){
    string s;
    while(n>0){
        s+=n%2 +'0';
        n/=2;
    }
    while(s.size()<4)s+='0';
    reverse(begin(s),end(s));
    
    return s;
}

int charHex(char k){
    if('0'<=k&&k<='9'){
        return k-'0';
    }
    else return 10+k-'A';
}

string decode(string s){
    string res;
    for(char i:s)res+=DecToBits(charHex(i));
    
    return res;
}

// KMP
// void solve(string A,string B){
//     string s=A+'#'+B;
//     int n=s.size();
    
//     vector<int>pi(n);
//     pi[0]=0;
    
//     int ans=0;
//     for(int i=1;i<n;++i){
//         int j=pi[i-1];
//         while(j>0&&s[j]!=s[i]){
//             j=pi[j-1];
//         }
//         if(s[j]==s[i]){
//             ++j;
//         }
        
//         if(j==(int)A.size()){
//             ++ans;
//         }
//         pi[i]=j;
//     }
    
//     cout<<ans<<'\n';
// }

int getHash(int i,int j,const vector<int>&hash,const vector<int>&powhash,const int&MOD){
    return ((hash[j]-hash[i-1]*powhash[j-i+1])%MOD+MOD)%MOD;
}

void solve(string B,string A){
    int n=A.size(),m=B.size();
    
    A='#'+A;
    B='#'+B;
    const int BASE=11,MOD=1e9+9;
    vector<int>hash(n+1),powhash(n+1);
    
    powhash[0]=1;
    for(int i=1;i<=n;++i){
        powhash[i]=(powhash[i-1]*BASE)%MOD;
        hash[i]=(hash[i-1]*BASE+(A[i]-'0'+1))%MOD;
    }
    
    int target_hash=0;
    for(int i=1;i<=m;++i){
        target_hash=(target_hash*BASE+(B[i]-'0'+1))%MOD;
    }
    
    int ans=0;
    for(int i=m;i<=n;++i){
        if(getHash(i-m+1,i,hash,powhash,MOD)==target_hash){
            ++ans;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string A,B;
    cin>>A>>B;
    
    solve(decode(A),decode(B));
    return 0;
}
