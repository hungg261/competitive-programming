#include<bits/stdc++.h>
using namespace std;

long long get(int value, const vector<int>& arr){
    long long res = 0;
    for(const int& ele: arr){
        res += abs(ele - value);
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    vector<int> p(n);
    for(int& ele: p) cin >> ele;
    sort(begin(p), end(p));

    long long ans;
    if(n & 1) ans = get(p[n / 2], p);
    else ans = min(get(p[n / 2], p), get(p[n / 2 - 1], p));

    cout << ans << '\n';

    return 0;
}
