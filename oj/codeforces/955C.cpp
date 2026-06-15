/******************************************************************************
Link: https://codeforces.com/problemset/problem/955/C
Code: 955C
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-15-19.03.45
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXVAL = 1e18;
vector<int> V;

int power(int A, int B){
    int res = 1;
    while(B--) res *= A;
    return res;
}

int root(int X, int P){
    int res = pow(X, 1.0 / P);
    while(power(res, P) > X) --res;
    while(power(res + 1, P) <= X) ++res;
    return res;
}

bool ispow(int X, int P){
    return power(root(X, P), P) == X;
}

void compute(){
    for(int v = 2; v * v * v * v <= MAXVAL; ++v){
        int p = v * v;
        while(true){
            if(!ispow(p, 2) && !ispow(p, 3)) V.push_back(p);
            if(p > MAXVAL / v) break;
            p *= v;
        }
    }
    sort(begin(V), end(V));
    V.erase(unique(begin(V), end(V)), end(V));
}

void solve(){
    int L, R;
    cin >> L >> R;

    auto cnt = [](int N){
        int cnt1 = upper_bound(begin(V), end(V), N) - begin(V);
        int cnt2 = root(N, 2) + root(N, 3) - root(N, 6);
        return cnt1 + cnt2;
    };

    cout << cnt(R) - cnt(L - 1) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    compute();
    while(t--){
        solve();
    }

    return 0;
}
