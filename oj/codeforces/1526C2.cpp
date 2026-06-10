#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int n, arr[MAXN + 5];

void solve(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        sum += arr[i];
        pq.push(arr[i]);

        if(sum < 0){
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << pq.size() << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("SOLVE.INP","r",stdin);
//    freopen("SOLVE.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    solve();

    return 0;
}
