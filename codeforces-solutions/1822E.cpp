/******************************************************************************
Link: https://codeforces.com/problemset/problem/1822/E
Code: 1822E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-23-18.27.22
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;

    cin >> n >> s;

    s = "#" + s;

    if(n & 1){
        cout << "-1\n";
        return;
    }

    int cnt[26] = {};
    for(int i = 1; i <= n; ++i){
        if(++cnt[s[i] - 'a'] > n / 2){
            cout << "-1\n";
            return;
        }
    }

    pair<int, int> bad[26] = {};
    for(int c = 0; c < 26; ++c) bad[c] = {0, c};

    for(int i = 1; i <= n / 2; ++i){
        if(s[i] == s[n - i + 1]){
            ++bad[s[i] - 'a'].first;
        }
    }

    sort(bad, bad + 26);
    multiset<pair<int, int>> ms;
    for(int i = 0; i < 26; ++i){
        if(bad[i].first > 0) ms.insert(bad[i]);
    }

    int res = 0;
    while(ms.size() > 1){
        auto it1 = ms.begin();
        auto it2 = prev(ms.end());

        auto a = *it1;
        auto b = *it2;

        ms.erase(it1);
        ms.erase(it2);

        a.first--;
        b.first--;
        res++;

        if(a.first > 0) ms.insert(a);
        if(b.first > 0) ms.insert(b);
    }

    if(ms.empty()){
        cout << res << '\n';
        return;
    }

    int left, target;
    tie(left, target) = *ms.begin();


    char ch = target + 'a';
    if(left > 0) for(int i = 1; i <= n / 2; ++i){
        if(s[i] != ch && s[n - i + 1] != ch){
            ++res;
            --left;
            if(left == 0) break;
        }
    }

    cout << res << '\n';
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
