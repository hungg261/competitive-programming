/******************************************************************************
Link: https://codeforces.com/contest/296/problem/C
Code: 296C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-23-09.37.03
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5, MAXQ = 1e5;

int n, m, k;
int Qdiff[MAXQ + 5], Adiff[MAXN + 5];
int arr[MAXN + 5];
tuple<int, int, int> Q[MAXQ + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    for(int i = 1; i <= m; ++i){
        int l, r, d;
        cin >> l >> r >> d;

        Q[i] = {l, r, d};
    }

    for(int i = 1; i <= k; ++i){
        int x, y;
        cin >> x >> y;

        Qdiff[x]++;
        Qdiff[y + 1]--;
    }

    int pre = 0;
    for(int i = 1; i <= m; ++i){
        pre += Qdiff[i];

        int l, r, d;
        tie(l, r, d) = Q[i];

        Adiff[l] += d * pre;
        Adiff[r + 1] -= d * pre;
    }

    int preA = 0;
    for(int i = 1; i <= n; ++i){
        preA += Adiff[i];

        cout << arr[i] + preA << ' ';
    }

    return 0;
}
