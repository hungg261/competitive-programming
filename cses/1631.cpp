#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    int maxval = *max_element(begin(arr), end(arr)),
        sum = accumulate(begin(arr), end(arr), 0LL);

    int ans = max(maxval * 2, sum);
    cout << ans << '\n';

    return 0;
}
