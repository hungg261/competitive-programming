#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
pair<int, int> mark[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 0; i <= MAXN; ++i) mark[i] = {-1, -1};
    for(int i = 0; i * i <= MAXN; ++i){
        for(int j = i; i * i + j * j <= MAXN; ++j){
            mark[i * i + j * j] = {i, j};
        }
    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int sum = 0; sum <= n; ++sum){
            if(mark[sum].first != -1 && mark[n - sum].first != -1){
                cout << mark[sum].first << ' ' << mark[sum].second << ' ' << mark[n - sum].first << ' ' << mark[n - sum].second << '\n';
                break;
            }
        }
    }

    return 0;
}
