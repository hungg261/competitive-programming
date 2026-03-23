#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<string> arr(n);
    for(string& s: arr) cin >> s;

    sort(begin(arr), end(arr), [](const string& x, const string& y){
            return x + y < y + x;
         });

    for(const string& s: arr){
        cout << s;
    }
    cout << '\n';

    return 0;
}
