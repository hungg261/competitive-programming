/******************************************************************************
Link: https://cses.fi/problemset/task/2207
Code: 2207
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-26-22.28.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

namespace StressTest{

int mex(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<bool> present(n + 1, false);

    for (int x : arr) {
        if (x >= 0 && x <= n) {
            present[x] = true;
        }
    }

    int mex = 0;
    while (present[mex]) {
        mex++;
    }

    return mex;
}

int memo[MAXN + 5];
int G(int n){
    if(n <= 1) return 0;
    else if(memo[n] != -1) return memo[n];

    vector<int> S;
    for(int i = 1; i * 2 < n; ++i){
        S.push_back(G(i) ^ G(n - i));
    }

    return memo[n] = mex(S);
}

void compute(){
//    memset(memo, -1, sizeof memo);
//    for(int i = 1; i <= (int)1000; ++i){
//        cerr << (G(i) > 0) << " ";
//    }

    memo[1] = 0;
//    int counter = 0;
    for(int n = 2; n <= 2000; ++n){
        vector<int> S;
        for(int i = 1; i * 2 < n; ++i){
            S.push_back(memo[i] ^ memo[n - i]);
        }

        memo[n] = mex(S);
//        if(memo[n] == 0) ++counter;
//        if(n % 2000 == 0) cerr << "running: " << n << " " << counter << "\n";
    }

//    for(int n = 1; n <= 1000000; ++n){
//        if(memo[n] == 0){
//            cerr << n << ", ";
//        }
//    }
}

}

void solve(){
    int n;
    cin >> n;

    cout << (n > 2000 || StressTest::memo[n] > 0 ? "first" : "second") << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    StressTest::compute();

    while(t--){
        solve();
    }

    return 0;
}
