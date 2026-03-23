/******************************************************************************
Link: https://marisaoj.com/problem/270
Code: 270
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-10-10.16.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e5;
int n, q;
int A[MAXN + 5], B[MAXN + 5];
int hashA[MAXN + 5], hashB[MAXN + 5];
set<int> check;
map<int, int> mp;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> A[i];

        if(!mp.count(A[i])) mp[A[i]] = rng();
        int xhash = check.count(A[i]) ? 0 : mp[A[i]];

        hashA[i] = hashA[i - 1] ^ xhash;

        check.insert(A[i]);
    }
    check.clear();
    for(int i = 1; i <= n; ++i){
        cin >> B[i];

        if(!mp.count(B[i])) mp[B[i]] = rng();
        int xhash = check.count(B[i]) ? 0 : mp[B[i]];

        hashB[i] = hashB[i - 1] ^ xhash;

        check.insert(B[i]);
    }

    while(q--){
        int i, j;
        cin >> i >> j;

        cout << (hashA[i] == hashB[j] ? "YES\n" : "NO\n");
    }

    return 0;
}
