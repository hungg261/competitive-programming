/******************************************************************************
Link: https://codeforces.com/problemset/problem/1861/C
Code: 1861C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-02-11.05.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string S;
    cin >> S;

    vector<int> cnt;
    vector<int> plus;
    int last1 = -1;
    int cur = 0;
    for(int i = 0; i < (int)S.size(); ++i){
        char c = S[i];

        if(c == '+'){
            cnt.push_back(1);
            plus.push_back(i);
            cur++;
        }
        else if(c == '-'){
            cur -= cnt.back();
            cnt.pop_back();
            plus.pop_back();
        }
        else if(c == '0'){
            if(cnt.size() < 2 || plus.back() < last1){
                cout << "NO\n";
                return;
            }

            cur -= cnt.back();
            cnt.pop_back();
            cnt.push_back(0);
        }
        else{
            if(cur < (int)cnt.size()){
                cout << "NO\n";
                return;
            }

            last1 = i;
        }
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
