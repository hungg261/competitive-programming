/******************************************************************************
Link: https://codeforces.com/problemset/problem/2203/D
Code: 2203D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-17-16.58.12
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    const int MAX = n + m;
    vector<int> freq(MAX + 1, 0);
    vector<int> dcnt(MAX + 1, 0);
    vector<int> a(n, 0), b(m, 0);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        freq[a[i]]++;
    }
    for(int i = 0; i < m; ++i) cin >> b[i];

    for(int i = 1; i <= MAX; ++i){
        if(freq[i]) for(int j = i; j <= MAX; j += i){
            dcnt[j] += freq[i];
        }
    }

    int cnt[2] = {};
    int middle = 0;
    for(int j = 0; j < m; ++j){
        if(dcnt[b[j]] == 0) ++cnt[1];
        else if(dcnt[b[j]] == n) ++cnt[0];
        else ++middle;
    }

    if(middle & 1) ++cnt[0];

    cout << (cnt[1] >= cnt[0] ? "Bob" : "Alice") << "\n";
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
