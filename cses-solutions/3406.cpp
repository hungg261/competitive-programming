#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXVAL = 1e12;
vector<int> store;
void compute(){
    for(int i = 1; i * (i + 1) / 2 <= MAXVAL; ++i){
        store.push_back(i * (i + 1) / 2);
    }
}

void solve(){
    int n;
    cin >> n;

    if(binary_search(begin(store), end(store), n)){
        cout << "1\n";
        return;
    }

    int i = 0, j = (int) store.size() - 1;
    while(i <= j){
        if(store[i] + store[j] == n){
            cout << "2\n";
            return;
        }
        else if(store[i] + store[j] < n){
            ++i;
        }
        else{
            --j;
        }
    }

    cout << "3\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    compute();
    while(t--){
        solve();
    }

    return 0;
}
