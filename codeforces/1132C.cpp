/******************************************************************************
Link: https://codeforces.com/contest/1132/problem/C
Code: 1132C
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-30-15.54.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000, MAXQ = 5000;
int n, q;
vector<pair<int, int>> queries;

void solve(){

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= q; ++i){
        int l, r;
        cin >> l >> r;

        queries.emplace_back(l, r);
    }

    solve();

    return 0;
}
