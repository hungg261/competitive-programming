#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;

    int n = s.size();

    int ans = 1;
    int consecutive = 1;
    for(int i = 1; i < n; ++i){
        if(s[i-1] == s[i]){
            ++consecutive;
        }
        else{
            ans = max(ans, consecutive);
            consecutive = 1;
        }
    }
    ans = max(ans, consecutive);

    cout << ans << '\n';
    return 0;
}
