#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXVAL = 1e6;
int n, a[MAXN + 5], mark[MAXVAL + 5];
long long dcnt[MAXVAL + 5];

void precompute(){
    for(int i = 1; i <= MAXVAL; ++i){
        for(int j = i; j <= MAXVAL; j += i){
            dcnt[i] += mark[j];
        }
        dcnt[i] = dcnt[i] * (dcnt[i] - 1) / 2;
    }
}

void solve(){
    for(int i = MAXVAL; i >= 1; --i){
        for(int j = i * 2; j <= MAXVAL; j += i){
            dcnt[i] -= dcnt[j];
        }
    }

    cout << dcnt[1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        ++mark[a[i]];
    }

    precompute();
    solve();
    return 0;
}
