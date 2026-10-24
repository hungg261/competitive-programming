/******************************************************************************
Link: https://atcoder.jp/contests/abc480/tasks/abc480_a
Code: abc480_a
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-24-13.50.41
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s[2];
    cin >> s[0] >> s[1];

    pair<int, int> last = {-1, -1};
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            if(s[i][j] == 'A' || s[i][j] == 'D'){
                if(abs(i - last.first) + abs(j - last.second) == 1){
                    cout << "Yes\n";
                    return 0;
                }
                last = {i, j};
            }
        }
    }

    cout << "No\n";

    return 0;
}
