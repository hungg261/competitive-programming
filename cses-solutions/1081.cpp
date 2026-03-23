#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXVAL = 1e6;
int n, mark[MAXVAL + 5];

void solve(){
    for(int i = MAXVAL; i >= 1; --i){
        vector<int> candidates;
        for(int j = MAXVAL / i * i; j >= i; j -= i){
            int markj = mark[j];
            while(markj > 0 && (int) candidates.size() < 2){
                candidates.push_back(j);
                --markj;
            }

            if((int) candidates.size() >= 2){
                cout << __gcd(candidates[0], candidates[1]) << '\n';
                return;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;

        ++mark[cur];
    }

    solve();
    return 0;
}
