/******************************************************************************
Link: https://open.kattis.com/problems/criticalelements
Code: criticalelements
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-25-18.45.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

vector<int> LIS(const vector<int> &arr){
    if(arr.empty()) return {};
    vector<int> tail, dp;

    for(int i = 0; i < (int)arr.size(); ++i){
        if(tail.empty() || arr[i] > tail.back()){
            tail.push_back(arr[i]);
            dp.push_back(tail.size());
        }
        else{
            auto it = lower_bound(begin(tail), end(tail), arr[i]);
            *it = arr[i];
            dp.push_back(it - begin(tail) + 1);
        }
    }

    return dp;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> L = LIS(a), R;

    {
        reverse(begin(a), end(a));
        for(int &ele: a) ele = -ele;

        R = LIS(a);
        reverse(begin(R), end(R));

        reverse(begin(a), end(a));
        for(int &ele: a) ele = -ele;
    }

    int lis = *max_element(begin(L), end(L));
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; ++i){
        if(L[i] + R[i] - 1 == lis) ++cnt[L[i]];
    }

    vector<int> res;
    for(int i = 0; i < n; ++i){
        if(L[i] + R[i] - 1 == lis && cnt[L[i]] == 1){
            res.push_back(a[i]);
        }
    }

    sort(begin(res), end(res));

    if(res.empty()) cout << "-1\n";
    else{
        for(int x: res) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
