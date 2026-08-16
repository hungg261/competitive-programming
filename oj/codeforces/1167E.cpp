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
int preL[MAXVAL + 5], sufF[MAXVAL + 5];
void solve(){
    memset(last, 0x3f, sizeof last);
    for(int i = 1; i <= n; ++i) last[arr[i]] = i;

    memset(first, -0x3f, sizeof first);
    for(int i = n; i >= 1; --i) first[arr[i]] = i;

    int r = n + 1;
    sufF[n + 1] = INT_MAX;
    for(int v = x; v >= 1; --v){
        if(first[v] < 0){
            sufF[v] = r;
        }
        else if(last[v] < r){
            r = first[v];
            sufF[v] = r;
        }
        else{
            r = v;
            break;
        }
    }

    int l = INT_MIN;
    preL[0] = INT_MIN;
    for(int v = 1; v <= x; ++v){
        if(first[v] < 0){
            preL[v] = l;
        }
        else if(first[v] > l) {
            l = last[v];
            preL[v] = l;
        }
        else{
            l = v;
            break;
        }
    }

    cerr << l << " " << r << endl;
    for(int v = 1; v <= x; ++v){
        cerr << preL[v] << "\t" << sufF[v] << "\n";
    }

    int res = 0;
    for(int i = 0, j = r + 1; preL[i]; ++i){
        while(j <= n + 1 && (i >= j || preL[i] > sufF[j])) ++j;

        res += x + 1 - j + 1;
        cerr << i << " " << j << "\n";
    }

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
