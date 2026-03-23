#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;

    vector<bool> mark(n + 1, false);
    for(int i = 1; i <= n - 1; ++i){
        int cur;
        cin >> cur;

        mark[cur] = true;
    }

    for(int num = 1; num <= n; ++num){
        if(!mark[num]){
            cout << num << '\n';
            break;
        }
    }
    return 0;
}
