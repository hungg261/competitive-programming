#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
void solve(){
    int n=s.size();

    int thoi_gian=0,bat_tay=0,demR=0;
    for(int i=0;i<n;++i){
        if(s[i]=='L'){
            bat_tay+=demR;
            if(demR>0)thoi_gian=max(thoi_gian+1,demR);
        }
        else ++demR;
    }
    cout<<thoi_gian<<' '<<bat_tay<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;

    solve();
    return 0;
}
