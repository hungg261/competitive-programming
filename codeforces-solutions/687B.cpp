/******************************************************************************
Link: https://codeforces.com/problemset/problem/687/B
Code: 687B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-20-14.04.04
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXVAL = 1e6;
int mindiv[MAXVAL + 5];
void sieve(){
    for(int i = 2; i * i <= MAXVAL; ++i){
        if(mindiv[i] == 0){
            for(int j = i * i; j <= MAXVAL; j += i){
                if(mindiv[j] == 0) mindiv[j] = i;
            }
        }
    }
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    vector<int> mu(MAXVAL + 5, 0);
    for(int i = 1; i <= n; ++i){
        int cur = arr[i];

        while(cur > 1){
            int p = mindiv[cur];
            if(p == 0) p = cur;

            int m = 0;
            while(cur % p == 0){
                cur /= p;
                ++m;
            }
            mu[p] = max(mu[p], m);
        }

    }

    while(k > 1){
        int p = mindiv[k];
        if(p == 0) p = k;

        int d = 0;
        while(k % p == 0){
            k /= p;
            ++d;
        }

        if(d > mu[p]){
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    sieve();
    while(t--){
        solve();
    }

    return 0;
}
