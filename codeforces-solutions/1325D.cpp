#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 1e18, BIT = __lg(MAX) + 1;


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int u, v;
    cin >> u >> v;

    int temp = v;

    int bitcnt[BIT] = {};
    for(int bitpos = BIT; bitpos >= 0; --bitpos){
        int bit = u >> bitpos & 1LL;

        int pow2 = 1LL << bitpos;
        int cnt = v / pow2;
        if((cnt & 1) != bit) --cnt;

//        cerr << bitpos << ": " << cnt << " | " << bit << ' ' << v << '\n';
        if(cnt > 0){
            v -= pow2 * cnt;
            bitcnt[bitpos] += cnt;
        }
        else if(bit){
            if(temp > u && (temp - u) % 2 == 0){
                cout << "3\n";
                cout << (temp - u) / 2 << ' ' << (temp - u) / 2 << ' ' << u << '\n';
                return 0;
            }
            cout << "-1\n";
            return 0;
        }
    }

    if(v > 0){

        if(temp > u && (temp - u) % 2 == 0){
            cout << "3\n";
            cout << (temp - u) / 2 << ' ' << (temp - u) / 2 << ' ' << u << '\n';
            return 0;
        }

        cout << "-1\n";
        return 0;
    }

    vector<int> res;
    for(int i = 0; ; ++i){
        int cur = 0;
        bool found = false;
        for(int j = 0; j < BIT; ++j){
            if(bitcnt[j] > 0){
                cur += 1LL << j;
                --bitcnt[j];

                found = true;
            }
        }

        if(!found) break;
        res.push_back(cur);
    }

    cout << res.size() << '\n';
    for(int ele: res) cout << ele << ' '; cout << '\n';

    return 0;
}
