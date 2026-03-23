#include<bits/stdc++.h>
#define int long long
using namespace std;

void run(const string& cmd){
    cout << cmd << endl;

    string status; cin >> status;
    if(status == "-1") exit(0);
}

void solve(){
    int n;
    cin >> n;

    run("mul 9");
    run("digit");
    run("digit");
    run("digit");
    run("div 9");
    run("mul " + to_string(n));

    run("!");
}

signed main(){
//    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
