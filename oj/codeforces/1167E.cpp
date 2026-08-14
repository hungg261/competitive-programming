/******************************************************************************
Link: https://codeforces.com/contest/1167/problem/E
Code: 1167E
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-14-15.21.12
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6, MAXVAL = 1e6;
int n, x, arr[MAXN + 5];

int first[MAXVAL + 5], last[MAXVAL + 5];
void solve(){
    memset(first, 0, sizeof last);
    for(int i = 1; i <= n; ++i) last[arr[i]] = i;

    memset(first, 0x3f, sizeof first);
    for(int i = n; i >= 1; --i) first[arr[i]] = i;

    int r = n + 1;
    for(int v = x; v >= 1; --v){
        if(last[v] < r) r = first[v];
        else{
            break;
        }
    }

    int l = 0;
    for(int v = 1; v <= x; ++v){
        if(first[v] > l) l = last[v];
        else{
            l = v;
            break;
        }
    }

    cerr << l << " " << r << endl;

    int res = min(x * (x + 1) / 2, (x - r + 1) * l);
    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    solve();

    return 0;
}
