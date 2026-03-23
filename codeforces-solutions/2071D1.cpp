/******************************************************************************
Link: https://codeforces.com/contest/2071/problem/D1
Code: 2071D1
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-30-22.13.41
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> preXor;
int n;

int get(int x);

int prefix(int x){
    if(x <= n){
        return preXor[x];
    }

    if(x & 1){
        return preXor[n];
    }
    else{
        return prefix(x - 1) ^ get(x);
    }
}

int get(int x){
    if(x <= n){
        return preXor[x] ^ preXor[x - 1];
    }

    return prefix(x >> 1);
}

void solve(){
    int l, r;
    cin >> n >> l >> r;

    preXor.resize(n + 1);
    preXor[0] = 0;
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;

        preXor[i] = preXor[i - 1] ^ cur;
    }
    if(n % 2 == 0){
        ++n;
        preXor.push_back(preXor[n - 1] ^ preXor[n >> 1]);
    }

    cout << get(l) << '\n';
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
