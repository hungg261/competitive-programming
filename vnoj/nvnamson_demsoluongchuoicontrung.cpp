#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=3e5;
const int BASE1=31,MOD1=1e9+7;
const int BASE2=37,MOD2=1e9+9;

int hash1[MAX+5],hash2[MAX+5];
int powhash1[MAX+5],powhash2[MAX+5];

void compute() {
	powhash1[0]=1;
	for(int i=1; i<=MAX+1; ++i) {
		powhash1[i] = powhash1[i-1] * BASE1 % MOD1;
	}
	
	powhash2[0]=1;
	for(int i=1; i<=MAX+1; ++i) {
		powhash2[i] = powhash2[i-1] * BASE2 % MOD2;
	}
}

int hashPair(int first,int second){
    return (first<<32LL) ^ second;
}

int get_hash(int i, int j) {
	int h1 = ((hash1[j] - hash1[i-1] * powhash1[j - i + 1]) % MOD1 + MOD1) % MOD1;
	int h2 = ((hash2[j] - hash2[i-1] * powhash2[j - i + 1]) % MOD2 + MOD2) % MOD2;
	return hashPair(h1,h2);
}

void solve() {
	int n,m,k;
	string a,b;
	cin>>n>>m>>k>>a>>b;

	a='#'+a;
	b='#'+b;
    
    vector<int>getHash1,getHash2;
	for(int i=1; i<=n; ++i) {
		hash1[i] = (hash1[i-1] * BASE1 % MOD1 + (a[i]-'a'+1)) % MOD1;
		hash2[i] = (hash2[i-1] * BASE2 % MOD2 + (a[i]-'a'+1)) % MOD2;
		if(i>=k) {
			getHash1.push_back(get_hash(i-k+1,i));
		}
	}

	for(int j=1; j<=m; ++j) {
		hash1[j] = (hash1[j-1] * BASE1 % MOD1 + (b[j]-'a'+1)) % MOD1;
		hash2[j] = (hash2[j-1] * BASE2 % MOD2 + (b[j]-'a'+1)) % MOD2;
		if(j>=k) {
			getHash2.push_back(get_hash(j-k+1,j));
		}
	}

    int ans=0;
    sort(begin(getHash1),end(getHash1));
    sort(begin(getHash2),end(getHash2));
    
    
    int u=getHash1.size(),v=getHash2.size();
    int i=0,j=0;
    while(i<u&&j<v){
        if(getHash1[i]<getHash2[j])++i;
        else if(getHash1[i]>getHash2[j])++j;
        else{
            int ii=i+1,jj=j+1;
            while(ii<u&&getHash1[ii]==getHash1[i]){
                ++ii;
            }
            while(jj<v&&getHash2[jj]==getHash2[j]){
                ++jj;
            }
            
            ans+=(ii-i)*(jj-j);
            i=ii;
            j=jj;
        }
    }
    
	cout<<ans<<'\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;

	compute();
	while(t--) {
		solve();
	}
	return 0;
}
