#include<bits/stdc++.h>
using namespace std;

string a, b;
string res;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;

    sort(begin(a), end(a), greater<char>());
    if(a.size() < b.size()){
        cout << a << '\n';
        return 0;
    }

    [&](){

    int len = b.size();
    for(int chosen = 0; chosen < len; ++chosen){
        int sz = a.size();
        for(int i = 0; i < sz; ++i){
            if(a[i] < b[chosen]){
                res += a[i];
                for(int j = 0; j < sz; ++j){
                    if(j != i) res += a[j];
                }

                return;
            }
            else if(a[i] == b[chosen]){
                string left = a;
                left.erase(begin(left) + i);
                sort(begin(left), end(left));

                if(left <= b.substr(chosen + 1)){
                    res += a[i];
                    a.erase(begin(a) + i);

                    break;
                }
            }
        }
    }

    }();

    cout << res << '\n';

    return 0;
}
