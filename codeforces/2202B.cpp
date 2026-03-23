/******************************************************************************
Link: https://codeforces.com/contest/2202/problem/B
Code: 2202B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-23-21.58.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;

    cin >> n >> s;

    deque<char> dq;

    int dqcnt[2] = {};
    for(int i = 0; i < n; ++i){
        char cur = "ab"[i & 1];
        dq.push_back(cur);
        ++dqcnt[cur - 'a'];
    }

    int bcnt[2] = {};
    for(int i = n - 1; i >= 0; --i){
        if(s[i] == '?') continue;
        ++bcnt[s[i] - 'a'];
    }

    for(int i = 0; i < n; ++i){
        if(s[i] == '?'){
            if(dq.front() == dq.back()){
                --dqcnt[dq.front() - 'a'];
                s[i] = dq.front();
                dq.pop_front();

            }
            else{
                if(s[i + 1] == dq.front()) dq.pop_back();
                else dq.pop_front();

                --dqcnt[1 - (s[i + 1] - 'a')];
                s[i] = (1 - (s[i + 1] - 'a'));
            }
        }
        else if(s[i] == 'a'){
            if(dq.front() == 'a') dq.pop_front();
            else if(dq.back() == 'a') dq.pop_back();
            else{
                cout << "NO\n";
                return;
            }

            --dqcnt[0];
        }
        else if(s[i] == 'b'){
            if(dq.front() == 'b') dq.pop_front();
            else if(dq.back() == 'b') dq.pop_back();
            else{
                cout << "NO\n";
                return;
            }

            --dqcnt[1];
        }

//        for(char c: dq) cerr << c; cerr << '\n';
    }

    cout << "YES\n";
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
