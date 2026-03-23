#include<bits/stdc++.h>
#define int long long
using namespace std;

int maxSubSum(const vector<int>& arr, int l, int r){
    int res = 0;

    int cur = 0;
    for(int i = l; i <= r; ++i){
        cur = max(arr[i], cur + arr[i]);
        res = max(res, cur);
    }

    return res;
}

int minSubSum(const vector<int>& arr, int l, int r){
    int res = 0;

    int cur = 0;
    for(int i = l; i <= r; ++i){
        cur = max(-arr[i], cur - arr[i]);
        res = max(res, cur);
    }

    return -res;
}

pair<int, int> minmaxSubSum(const vector<int>& arr, int l, int r){
    pair<int, int> res;
    res.first = minSubSum(arr, l, r);
    res.second = maxSubSum(arr, l, r);

    return res;
}

int maxPreAfter(const vector<int>& arr, int idx){
    int n = arr.size();
    int best = 0, pre = 0;
    for(int i = idx; i < n; ++i){
        pre += arr[i];
        best = max(best, pre);
    }
    return best;
}

int minPreAfter(const vector<int>& arr, int idx){
    int n = arr.size();
    int best = 0, pre = 0;
    for(int i = idx; i < n; ++i){
        pre -= arr[i];
        best = max(best, pre);
    }
    return -best;
}

int maxPreBefore(const vector<int>& arr, int idx){
    int best = 0, pre = 0;
    for(int i = idx; i >= 0; --i){
        pre += arr[i];
        best = max(best, pre);
    }
    return best;
}

int minPreBefore(const vector<int>& arr, int idx){
    int best = 0, pre = 0;
    for(int i = idx; i >= 0; --i){
        pre -= arr[i];
        best = max(best, pre);
    }
    return -best;
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    int distinct = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(abs(arr[i]) != 1) distinct = i;
    }

    pair<int, int>  bef = minmaxSubSum(arr, 0, distinct - 1),
                    aft = minmaxSubSum(arr, distinct + 1, n - 1);
    int minPreBef = minPreBefore(arr, distinct - 1),
        maxPreBef = maxPreBefore(arr, distinct - 1),
        minPreAft = minPreAfter(arr, distinct + 1),
        maxPreAft = maxPreAfter(arr, distinct + 1);

    int L = arr[distinct] + minPreBef + minPreAft, R = arr[distinct] + maxPreBef + maxPreAft;

    vector<int> values;
    for(int i = bef.first; i <= bef.second; ++i) values.push_back(i);
    for(int i = aft.first; i <= aft.second; ++i) values.push_back(i);
    for(int i = L; i <= R; ++i) values.push_back(i);
    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));

    cout << values.size() << '\n';
    for(int v: values) cout << v << ' '; cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
