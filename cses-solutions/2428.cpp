#include<bits/stdc++.h>
using namespace std;

void compress(vector<int>& arr){
    vector<int> temp = arr;
    sort(begin(temp), end(temp));

    for(int& ele: arr){
        ele = lower_bound(begin(temp), end(temp), ele) - begin(temp);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for(int& ele: x) cin >> ele;
    compress(x);

    vector<int> mark(n);

    int i = 0, unique_cnt = 0;
    long long ans = 0;
    for(int j = 0; j < n; ++j){
        if(mark[x[j]] == 0) ++unique_cnt;
        ++mark[x[j]];

        while(unique_cnt > k){
            --mark[x[i]];
            if(mark[x[i]] == 0) --unique_cnt;

            ++i;
        }

        ans += j - i + 1;
    }

    cout << ans << '\n';

    return 0;
}
