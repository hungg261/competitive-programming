#include<bits/stdc++.h>
using namespace std;

void compress(vector<int>& arr, int n){
    vector<int> temp = arr;
    sort(begin(temp) + 1, end(temp));

    for(int i = 1; i <= n; ++i){
        arr[i] = lower_bound(begin(temp) + 1, end(temp), arr[i]) - begin(temp);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    compress(arr, n);
    vector<int> mark(n + 5, 0);

    int i = 1, ans = 1;
    for(int j = 1; j <= n; ++j){
        while(mark[arr[j]]){
            --mark[arr[i]];
            ++i;
        }
        ++mark[arr[j]];

        ans = max(ans, j - i + 1);
    }

    cout << ans << '\n';

    return 0;
}
