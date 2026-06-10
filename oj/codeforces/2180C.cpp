/******************************************************************************
Link: https://codeforces.com/contest/2180/problem/C
Code: 2180C
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-31-18.51.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(k, 0);
    vector<int> tight, loose;
    for(int i = 0; i < k; ++i) tight.push_back(i);

    for(int b = 30; b >= 0; --b){
        if(n >> b & 1){
            if(k & 1) for(int& ele: a) ele |= 1 << b;
            else{
                if(!tight.empty()){
                    loose.push_back(tight.back());
                    tight.pop_back();
                }

                for(int i = 0; i < k - 1; ++i){
                    if(i < (int)tight.size()) a[tight[i]] |= 1 << b;
                    else{
                        for(int j = 0; i + j < k - 1; ++j){
                            a[loose[j]] |= 1 << b;
                        }
                        break;
                    }
                }
            }
        }
        else{
            if(loose.size() & 1) for(int i = 0; i + 1 < (int)loose.size(); ++i) a[loose[i]] |= 1 << b;
            else for(int i = 0; i < (int)loose.size(); ++i) a[loose[i]] |= 1 << b;
        }
    }

    for(int ele: a) cout << ele << " ";
    cout << "\n";
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
