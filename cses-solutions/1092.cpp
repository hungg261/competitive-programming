#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;

    if(n * (n + 1) / 2 % 2 != 0 || (n + 1) / 2 % 2 != 0){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<int> result[2];
    if(n % 2 == 1){
        for(int i = n; i >= 3; i -= 2){
            int step = (i - 1) / 2 % 2 == 0;

            result[step].push_back(i);
            result[1 - step].push_back(i - 1);
        }
        result[1].push_back(1);
    }
    else{
        for(int i = 1; i <= n / 4; ++i){
            result[0].push_back(i);
            result[0].push_back(n - i + 1);
        }
        for(int i = n / 4 + 1; i <= n / 2; ++i){
            result[1].push_back(i);
            result[1].push_back(n - i + 1);
        }
    }

    for(int idx = 0; idx < 2; ++idx){
        cout << (int)result[idx].size() << '\n';
        for(int element: result[idx]){
            cout << element << ' ';
        }

        cout << '\n';
    }


    return 0;
}
