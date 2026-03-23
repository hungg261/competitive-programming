#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
int arr[MAXN + 5], n;

void fail(){
    cout << "NO\n";
    exit(0);
}

void solve(){
    long long sum = accumulate(arr + 1, arr + n + 1, 0LL);
    if(sum & 1) fail();

    int maxVal = *max_element(arr + 1, arr + n + 1);
    if(maxVal > sum - maxVal) fail();

    cout << "YES\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    solve();

    return 0;
}
