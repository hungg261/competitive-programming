#include<bits/stdc++.h>
using namespace std;

const int MAXN=1700;
int n,a[MAXN];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        
        unordered_map<int,int>freq;
        long long total=0;
        for(int k=n-1;k>=0;--k){
            for(int i=0;i<k;++i){
                int target=2*a[k]-a[i];
                if(freq.count(target)){
                    total+=freq[target];
                }
            }
            ++freq[a[k]];
        }
        
        cout<<total<<'\n';
    }
    return 0;
}
