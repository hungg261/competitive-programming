/******************************************************************************
Link: https://oj.vnoi.info/problem/demen_08_calculate
Code: demen_08_calculate
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-08-12.04.52
*******************************************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,p;
const int maxn = 1e5;
const int mod = 1e9 + 7;
int mang[maxn + 7];
int pref[maxn + 7];
int ans[maxn + 7];
int ba[maxn + 7];

void input(){
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        cin >> mang[i];
        pref[i] = (pref[i - 1] + i * mang[i]) % mod;
    }
}
int Pow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1){
            res *= a;
        }
        a *= a;
        a %= mod;
        res %= mod;
        b /= 2;
    }
    return res;
}
void solve(){
    int res = 0;
    if(p == 1){
        for(int i = 1;i <= n;i++){
            res += i * (n - i + 1) * mang[i];
            res %= mod;
        }
        cout<<res;
    }
    else if(p == 2){
        for(int i = 1;i <= n;i++){
            ans[i] = ((ans[i - 1] + 2 * mang[i] % mod * pref[i - 1] % mod) % mod + i * mang[i] % mod * mang[i] % mod) % mod;
        }
        for(int i = 1;i <= n;i++){
            res += ans[i];
            res %= mod;
        }
        cout<<res;
    }
    else{
        for(int i = 1;i <= n;i++){
            ans[i] = ((ans[i - 1] + 2 * mang[i] % mod * pref[i - 1] % mod) % mod + i * mang[i] % mod * mang[i] % mod) % mod;
        }
        for(int i = 1;i <= n;i++){
            ba[i] = (((ba[i - 1] + 3 * mang[i] % mod * ans[i - 1] % mod) % mod + 3 * mang[i] % mod * mang[i] % mod * pref[i - 1] % mod)
            % mod + i * Pow(mang[i],3) % mod) % mod;
        }
        for(int i = 1;i <= n;i++){
            res += ba[i];
            res %= mod;
        }
        cout<<res;
    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    input();
    solve();

    return 0;
}
