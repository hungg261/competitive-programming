#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e6;
int n, mark[MAXN + 5];
long long a[MAXN + 5];

void solve(){
    sort(a + 1, a + n + 1);
    long long same = 0;
    
    int consecutive = 1;
    for(int i = 2; i <= n; ++i){
        if(a[i - 1] == a[i]){
            ++consecutive;
        }
        else{
            same += (long long)consecutive * (consecutive - 1) / 2;
            consecutive = 1;
        }
    }
    same += (long long)consecutive * (consecutive - 1) / 2;
    
    cout << same << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] ^= i;
    }
    
    solve();
    return 0;
}
