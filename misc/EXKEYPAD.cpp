/******************************************************************************
Link: https://www.codechef.com/START261D/problems/EXKEYPAD
Code: EXKEYPAD
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-21-21.46.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long

string solve(string N, char d){
    if(count(begin(N), end(N), d) == 0){
        return N;
    }

    int idx = find(begin(N), end(N), d) - begin(N);
    if(d == '9'){
        string pre = idx == 0 ? "0" : N.substr(0, idx);
        string suf = N.substr(idx);
        for(char &c: suf) c = '0';

        N = solve(to_string(stoll(pre) + 1), d) + suf;
    }
    else{
        string pre = idx == 0 ? "" : N.substr(0, idx);
        string suf = N.substr(idx);
        for(char &c: suf){
            if(d == '0') c = '1';
            else c = '0';
        }
        suf[0] = N[idx] + 1;

        N = pre + suf;    }

    return N;
}

void solve(){
    string N; char d;
    cin >> N >> d;

    cout << solve(N, d) << "\n";
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
