#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<vector<int>> arr(n * 2, vector<int>(n, 0));
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            arr[i][j] = arr[i + n][j] = ++cnt;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int c = 0; c < n; ++c){
            cout << arr[i + c][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
