/******************************************************************************
Link: https://oj.uz/problem/view/CEOI17_palindromic
Code: CEOI17_palindromic
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-21-16.49.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

namespace Hash{

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
bool isp(long long n){if(n<2)return 0;if(n<=3)return 1;if(n%2==0)return 0;long long d=n-1;int s=0;while(d%2==0)d/=2,s++;for(int i=0;i<5;i++){long long a=2+rng()%(n-3),x=1,b=a%n,e=d;while(e){if(e%2)x=(__int128)x*b%n;b=(__int128)b*b%n;e/=2;}if(x==1||x==n-1)continue;bool c=1;for(int r=1;r<s;r++){x=(__int128)x*x%n;if(x==n-1){c=0;break;}}if(c)return 0;}return 1;}
long long gp(){while(1){long long p=1e9+rng()%(long long)1e9;if(isp(p))return p;}}
struct Hash{long long BASE,MOD;vector<long long> hashes,powhash;Hash()=default;Hash(string S,long long _base=0,long long _mod=0){static long long s_mod=gp(),s_base=(rng()%(s_mod-256)+256)|1;MOD=_mod?_mod:s_mod;BASE=_base?_base:s_base;long long sz=S.size();hashes.resize(sz+1);powhash.resize(sz+1);S="#"+S;powhash[0]=1;hashes[0]=0;for(long long i=1;i<=sz;++i){hashes[i]=(hashes[i-1]*BASE+(unsigned char)S[i])%MOD;powhash[i]=powhash[i-1]*BASE%MOD;}}long long get(long long l,long long r){return ((hashes[r]-hashes[l-1]*powhash[r-l+1])%MOD+MOD)%MOD;}};
struct DHash{Hash hash1,hash2;DHash(const string& S){static long long m1=gp(),m2=gp();while(m1==m2)m2=gp();hash1=Hash(S,0,m1);hash2=Hash(S,0,m2);}pair<long long,long long> get(long long l,long long r){return {hash1.get(l,r),hash2.get(l,r)};}};

} using namespace Hash;

void solve(){
    string S;
    cin >> S;

    int N = S.size();
    DHash H(S);

    int res = 0;
    int i = 1;
    for(int j = 1; j * 2 <= N; ++j){
        int rev_i = N - j + 1, rev_j = N - i + 1;
        if(H.get(i, j) == H.get(rev_i, rev_j)){
            res += 2;
            i = j + 1;
        }
    }

    if(i * 2 - 1 <= N) ++res;

    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
