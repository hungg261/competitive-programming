/******************************************************************************
Link: https://codeforces.com/group/2W1wfqmLNZ/contest/675179/problem/A
Code: Group_2W1wfqmLNZ_675179A
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-13-15.07.41
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, q;
pair<int, int> status[MAXN + 5];
multiset<pair<int, int>> ms;

bool cmp(const pair<int, int>& x, const pair<int, int>& y){
    return (x.first > y.first) || (x.first == y.first && x.second < y.second);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) ms.insert({0, 0});
    for(int i = 1; i <= q; ++i){
        int T, P;
        cin >> T >> P;

        ms.erase(ms.find(status[T]));

        ++status[T].first;
        status[T].second += P;

        ms.insert(status[T]);

        int H = distance(ms.begin(), ms.upper_bound(status[1]));
        cout << n - H + 1 << '\n';
    }

    return 0;
}
