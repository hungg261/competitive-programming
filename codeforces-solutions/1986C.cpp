/******************************************************************************
Link: https://codeforces.com/problemset/problem/1986/C
Code: 1986C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-14-20.49.50
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    int n, m;
    cin >> n >> m;
    cin >> s;

    vector<int> ind(m);
    string c;

    for(int& ele: ind) cin >> ele;
    cin >> c;

    sort(begin(c), end(c));
    sort(begin(ind), end(ind));

    deque<char> dq;
    for(char ch: c) dq.push_back(ch);

    for(int i = 0; i < m; ++i){
        if(i > 0 && ind[i] == ind[i - 1]){
            dq.pop_back();
            continue;
        }

        s[ind[i] - 1] = dq.front();
        dq.pop_front();
    }

    cout << s << '\n';
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
