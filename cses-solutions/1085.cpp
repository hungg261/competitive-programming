#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(int mid, const vector<int>& arr, int k){
    int sum = 0, subcnt = 1;
    for(int ele: arr){
        if(ele > mid) return false;

        if(sum + ele > mid){
            ++subcnt;
            sum = ele;
        }
        else sum += ele;

        if(subcnt > k) return false;
    }

    return true;
}

int solve(const vector<int>& arr, int k){
    int l = 0, h = 1e15, res = -1;
    while(l <= h){
        int mid = (l + h) / 2;
        if(check(mid, arr, k)){
            res = mid;
            h = mid - 1;
        }
        else l = mid + 1;
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    cout << solve(arr, k) << '\n';

    return 0;
}
