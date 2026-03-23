#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(int value, int target, int n){
    int higher = 0;
    for(int row = 1; row <= n; ++row){
        int col = value / row + 1;
        higher += max(0LL, n - col + 1);
    }

    return higher <= target;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    int target = (n * n + 1) / 2 - 1;

    int l = 1, r = n * n, res = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid, target, n)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res << '\n';

    return 0;
}
