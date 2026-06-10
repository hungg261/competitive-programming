/******************************************************************************
Link: https://oj.uz/problem/view/JOI18_art
Code: JOI18_art
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-04-07.44.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5;
int n;
pair<int, int> art[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> art[i].first >> art[i].second;
    }
    sort(art + 1, art + n + 1);

    int minPre = LLONG_MAX;
    int prefix = 0;
    int res = 0;
    for(int i = 1; i <= n; ++i){
        int cur = prefix - art[i].first;
        prefix += art[i].second;

        minPre = min(minPre, cur);
        res = max(res, prefix - art[i].first - minPre);
    }

    cout << res << "\n";

    return 0;
}
