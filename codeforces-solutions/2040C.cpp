#include<bits/stdc++.h>
#define int long long
using namespace std;

int cnt(const vector<int>& arr){
    int res = 0;
    for(int i = 0; i < (int)arr.size(); ++i){
        int minVal = arr[i];
        for(int j = i; j < (int)arr.size(); ++j){
            minVal = min(minVal, arr[j]);
            res += minVal;
        }
    }

    return res;
}

vector<int> trau(int n, int k){
    vector<int> temp(n);
    iota(begin(temp), end(temp), 1);

    int best = -1;
    do{
        best = max(best, cnt(temp));
    } while(next_permutation(begin(temp), end(temp)));

    iota(begin(temp), end(temp), 1);
    vector<vector<int>> store;
    do{
        if(cnt(temp) == best){
            store.push_back(temp);
        }
    } while(next_permutation(begin(temp), end(temp)));

//    cout << best << ' ' << (int)store.size() << '\n';
//    for(const vector<int>& arr: store){
//        for(int ele: arr) cout << ele << ' ' ; cout << '\n';
//    }

//    cout << "\n\n";

    return store[k];
}

void solve(){
    int n, k;
    cin >> n >> k;

//    trau(n, k);

    if(n <= 60 && (1LL << (n - 1)) < k){
        cout << "-1\n";
        return;
    }
    --k;

    vector<int> bits;
    while(k > 0){
        bits.push_back(k & 1);
        k >>= 1;
    }
    while(bits.size() < n - 1) bits.push_back(0);

    vector<int> res(n, -1);
    int l = 0, r = n - 1;
    for(int i = 0; i < n - 1; ++i){
        if(bits[n - i - 2]) res[r--] = i + 1;
        else res[l++] = i + 1;
    }

    if(res[r] == -1) res[r] = n;
    if(res[l] == -1) res[l] = n;

    for(int ele: res) cout << ele << ' '; cout << '\n';

//    vector<int> tres = trau(n, k);
//    cerr << "trau: "; for(int ele: tres) cerr << ele << ' '; cerr << '\n';
//    cerr << (res == tres) << '\n';
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
