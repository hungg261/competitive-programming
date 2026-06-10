#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for(int& ele: a) cin >> ele;
    for(int& ele: b) cin >> ele;
    sort(begin(a), end(a));
    sort(begin(b), end(b));

    int i = 0, j = 0, ans = 0;
    while(i < n && j < m){
        if(a[i] - k <= b[j] && b[j] <= a[i] + k){
            ++i;
            ++j;

            ++ans;
        }

        if(a[i] - k > b[j]) ++j;
        if(a[i] + k < b[j]) ++i;
    }

    cout << ans << '\n';

    return 0;
}
