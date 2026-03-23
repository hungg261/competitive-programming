#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for(int& ele: p) cin >> ele;
    sort(begin(p), end(p));

    int i = 0, j = n - 1;
    int ans = 0;
    while(i <= j){
        if(p[i] + p[j] <= x){
            ++i;
        }
        --j;
        ++ans;
    }

    cout << ans << '\n';
    return 0;
}
