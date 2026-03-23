#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    vector<int> a(n);
    for(int& ele: a) cin >> ele;
    sort(begin(a), end(a));

    int prefix = 0;
    for(int ele: a){
        if(prefix + 1 < ele){
            cout << prefix + 1 << '\n';
            return 0;
        }

        prefix += ele;
    }

    cout << prefix + 1 << '\n';


    return 0;
}
