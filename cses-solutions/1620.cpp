#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(int mid, int t, const vector<int>& k){
    int res = 0;
    for(const int& ele: k){
        res += mid / ele;
        if(res >= t) return true;
    }
    return false;
}

int solve(int t, vector<int> k){
    int l = 0, r = 1e18, res = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid, t, k)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, t;
    cin >> n >> t;

    vector<int> k(n);
    for(int& ele: k) cin >> ele;

    cout << solve(t, k) << '\n';

    return 0;
}
