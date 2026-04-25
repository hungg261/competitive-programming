/******************************************************************************
Link: https://cses.fi/problemset/task/1142
Code: 1142
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-24-18.11.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5, MAXLG = __lg(MAXN) + 1;
int n;
pair<int, int> table[MAXN + 5][MAXLG + 1];

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

pair<int, int> query(int l, int r){
    int bit = __lg(r - l + 1);
    return min(table[l][bit], table[r - (1 << bit) + 1][bit]);
}

int solve(int l, int r){
    if(l > r) return 0;

    int value, mid;
    tie(value, mid) = query(l, r);

    return max({value * (r - l + 1),
               solve(l, mid - 1),
               solve(mid + 1, r)});
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> table[i][0].first;
        table[i][0].second = i;
    }

    compute();

    cout << solve(1, n) << "\n";

    return 0;
}
