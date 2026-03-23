/******************************************************************************
Link: https://codeforces.com/problemset/problem/2036/D
Code: 2036D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-04-20.16.28
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<vector<bool>> mark(n, vector<bool>(m, false));
    int res = 0;
    for(int layer = 0; layer < min(n, m); ++layer){
        if(mark[layer][layer]) break;

        int i = layer, j = layer;
        string str;
        while(0 <= i && i < n && 0 <= j && j < m && !mark[i][j]){
            str += arr[i][j];
            mark[i][j] = true;
            ++j;
        } --j, ++i;

        while(0 <= i && i < n && 0 <= j && j < m && !mark[i][j]){
            str += arr[i][j];
            mark[i][j] = true;
            ++i;
        } --i, --j;

        while(0 <= i && i < n && 0 <= j && j < m && !mark[i][j]){
            str += arr[i][j];
            mark[i][j] = true;
            --j;
        } ++j, --i;

        while(0 <= i && i < n && 0 <= j && j < m && !mark[i][j]){
            str += arr[i][j];
            mark[i][j] = true;
            --i;
        } ++i;

        for(int idx = 0; idx < (int)str.size(); ++idx){
            string sub;
            for(int jid = idx; jid < idx + 4; ++jid){
                sub += str[jid % (int)str.size()];
            }
            if(sub == "1543"){
                idx += 3;
                ++res;
            }
        }
    }

    cout << res << '\n';
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
