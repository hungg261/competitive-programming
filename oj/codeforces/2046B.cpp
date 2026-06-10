#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int INF = 1e9;
const int MAXN = 1e5;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    multiset<int> L, R;
    for(int i = 0; i < n; ++i)
        R.insert(arr[i]);

    vector<int> res;
    for(int i = 0; i < n; ++i){
        if(!L.empty() && *R.begin() > *L.begin()){
            while(!L.empty()){
                res.push_back(*L.begin());
                L.erase(L.begin());
            }
            for(int j = i; j < n; ++j){
                res.push_back(*R.begin() + 1);
                R.erase(R.begin());
            }
            break;
        }

        if(arr[i] == *R.begin()){
            res.push_back(arr[i]);
        }
        else{
            L.insert(arr[i] + 1);
        }

        R.erase(R.find(arr[i]));
    }

    while(!L.empty()){
        res.push_back(*L.begin());
        L.erase(L.begin());
    }
    while(!R.empty()){
        res.push_back(*R.begin());
        R.erase(R.begin());
    }

    sort(begin(res), end(res));
    for(int ele: res){
        cout << ele << ' ';
    }
    cout << '\n';
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
