#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    map<int, int> mark;
    int i = 1;

    long long ans = 0;
    for(int j = 1; j <= n; ++j){
        int ele; cin >> ele;

        i = max(i, mark[ele] + 1);
        ans += j - i + 1;

        mark[ele] = j;
    }

    cout << ans << '\n';

    return 0;
}
