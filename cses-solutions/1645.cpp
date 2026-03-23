#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    stack<int> sta;
    for(int i = 1; i <= n; ++i){
        while(!sta.empty() && arr[sta.top()] >= arr[i]) sta.pop();

        if(sta.empty()) cout << 0 << ' ';
        else cout << sta.top() << ' ';

        sta.push(i);
    }

    return 0;
}
