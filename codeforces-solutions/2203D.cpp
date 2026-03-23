/******************************************************************************
Link: https://codeforces.com/contest/2203/problem/D
Code: 2203D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-25-22.55.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];

    if(find(begin(a) + 1, end(a), 1) != end(a)){
        cout << "Alice\n";
        return;
    }

    map<int, int> mpA, mpB, cntA, cntB;
    for(int i = 1; i <= n; ++i) mpA[a[i]]++;
    for(int i = 1; i <= m; ++i) mpB[b[i]]++;

    const int MAX = n + m;
    for(int i = 1; i <= n; ++i){
        for(int j = a[i]; j <= MAX; j += a[i]){
            if(!mpB.count(j)) continue;

            ++cntB[j];
        }
    }

    multiset<pair<int, int>> ms;
    for(int i = 1; i <= m; ++i){
        ms.insert({cntB[b[i]], b[i]});
    }

//    for(auto p: ms){
//        cerr << p.first << ' ' << p.second << '\n';
//    }

    int turn = 0;
    while(!ms.empty()){
        if(turn == 0){
            auto it = prev(ms.end());
            if(it->first == 0){
                cout << "Bob\n";
                return;
            }

            ms.erase(it);
        }
        else{
            auto it = ms.begin();
            if(n - it->first == 0){
                cout << "Alice\n";
                return;
            }

            ms.erase(it);
        }

//        cerr << "-====== p ======-\n";
//        for(auto p: ms) cerr << p.first << ' ' << p.second << '\n'; cerr << '\n';
        turn ^= 1;
    }

    cout << (turn ? "Alice" : "Bob") << '\n';
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
