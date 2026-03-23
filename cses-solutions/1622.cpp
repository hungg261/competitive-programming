#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;

    sort(begin(s), end(s));
    set<string> res;
    do{
        res.insert(s);
    } while(next_permutation(begin(s),end(s)));

    cout << res.size() << '\n';
    for(const string& str: res){
        cout << str << '\n';
    }
    return 0;
}
