#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k){
    if(n == 1) return 1;

    if(n % 2 == 0){
        if(k <= n / 2) return k * 2;
        else return solve(n / 2, k - n / 2) * 2 - 1;
    }
    else{
        if(k == (n + 1) / 2) return 1;
        else if(k < (n + 1) / 2) return k * 2;
        else return solve(n / 2, k - (n + 1) / 2) * 2 + 1;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;

    for(int k = 1; k <= n; ++k){
        cout << solve(n, k) << ' ';
    }
    cout << '\n';
    return 0;
}
