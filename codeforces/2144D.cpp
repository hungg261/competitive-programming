/******************************************************************************
Link: https://codeforces.com/contest/2144/problem/D
Code: 2144D
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-26-13.40.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5;
void brute(){
    int n, y;
    cin >> n >> y;

    vector<int> c(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }

    auto Try = [&](int x){
        vector<int> temp = c;
        map<int, int> mp;
        for(int i = 1; i <= n; ++i){
            mp[temp[i]]++;
        }

        int res = 0;
        for(int i = 1; i <= n; ++i){
            temp[i] = (temp[i] + x - 1) / x;
            res += temp[i];

            if(--mp[temp[i]] < 0) res -= y;
        }

        return res;
    };

    for(int x = 1; x <= MAX; ++x){
        cerr << x << ": " << Try(x) << "\n";
    }
}

void solve(){
    int n, y;
    cin >> n >> y;

    vector<int> c(n + 1);
    int mx = INT_MIN;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
        mx = max(mx, c[i]);
    }

    vector<int> mp(MAX + 5);
    auto Try = [&](int x){
        fill(begin(mp) + 1, begin(mp) + mx + 1, 0);
        for(int i = 1; i <= n; ++i){
            ++mp[c[i]];
        }

        int res = 0;
        for(int i = 1; i <= n; ++i){
            int cur = (c[i] + x - 1) / x;
            res += cur;

            if(--mp[cur] < 0) res -= y;
        }

        return res;
    };

//    for(int x = 2; x <= mx + 1; ++x){
//        cerr << Try(x) << "\n";
//    }


}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
