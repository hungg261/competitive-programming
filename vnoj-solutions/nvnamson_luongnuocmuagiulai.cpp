#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6;
int n, a[MAXN + 5], premax[MAXN + 5], sufmax[MAXN + 5];

void compute(){
    premax[0] = 0;
    for(int i = 1; i <= n; ++i){
        premax[i] = max(premax[i - 1], a[i]);
    }
    
    sufmax[n + 1] = 0;
    for(int i = n; i >= 1; --i){
        sufmax[i] = max(sufmax[i + 1], a[i]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    
    compute();
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += max(0LL, min(premax[i - 1], sufmax[i + 1]) - a[i]);
    }
    
    cout << ans << '\n';
    return 0;
}
