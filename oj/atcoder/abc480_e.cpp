/******************************************************************************
Link: https://atcoder.jp/contests/abc480/tasks/abc480_e
Code: abc480_e
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-14.46.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
const int LIM = 1e9;

long long n;
long long ans = 0;

int calc(int a, int cnt){
    int s = 0, t = LIM;
    while(t - s > 1){
        int mid = (s + t) >> 1;
        long long P = n;
        for(int i = 0; i < cnt; ++i){
            P /= a + i * mid;
        }
        if(P) s = mid;
        else t = mid;
    }
    return s;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int a = 1; a <= MAX; ++a){
        int cnt = 3;
        long long cur = n / a / (a + 1) / (a + 2);
        while(cur){
            ans += calc(a, cnt);
            cur /= a + cnt;
            ++cnt;
        }
    }

    cout << ans << "\n";

    return 0;
}
