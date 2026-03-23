/******************************************************************************
Link: https://codeforces.com/contest/2039/problem/D
Code: 2039D
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-31-22.12.01
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 3e5;
int index[MAX + 5];
void compute(){
    index[1] = 0;
    for(int i = 1; i <= MAX; ++i){
        for(int j = i * 2; j <= MAX; j += i){
            index[j] = max(index[j], index[i] + 1);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(m);
    for(int& ele: arr) cin >> ele;

    sort(begin(arr), end(arr), greater<int>());

    for(int i = 1; i <= n; ++i){
        if(index[i] >= m){
            cout << "-1\n";
            return;
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << arr[index[i]] << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    compute();

    while(t--){
        solve();
    }

    return 0;
}
