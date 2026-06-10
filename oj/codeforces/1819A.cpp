/******************************************************************************
Link: https://codeforces.com/problemset/problem/1819/A
Code: 1819A
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-02-21.13.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    map<int, int> mp;
    for(int& ele: arr){
        cin >> ele;
        mp[ele]++;
    }

    auto find_mex = [](vector<int> arr){
        sort(begin(arr), end(arr));
        int mex = 0;
        for(int x: arr){
            if(x == mex) ++mex;
        }

        return mex;
    };

    int mex = find_mex(arr);
    pair<int, int> pos = {-1, -1};
    for(int i = 0; i < n; ++i){
        if(arr[i] == mex + 1){
            if(pos.first == -1) pos.first = i;
            pos.second = i;
        }
    }

    if(pos.first == -1){
        for(int i = 0; i < n; ++i){
            if(arr[i] > mex + 1 || (arr[i] != mex && mp[arr[i]] > 1)){
                arr[i] = mex;
                break;
            }
        }
    }
    else for(int i = pos.first; i <= pos.second; ++i){
        arr[i] = mex;
    }

    if(find_mex(arr) == mex + 1) cout << "YES\n";
    else cout << "NO\n";
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
