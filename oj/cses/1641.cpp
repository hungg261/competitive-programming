#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

struct CustomHash{
    static ull Mix(ull value){
        value += 0x9e3779b97f4a7c15;
        value = (value ^ (value >> 30)) * 0b0110110101110110010101011011010101101001001001110110011001110101ull;
        value = (value ^ (value >> 27)) * 0b1101010101011101100100111010010010100101101100101011011100101011ull;

        return value ^ (value >> 31);
    }

    size_t operator() (const ull& value) const{
        return Mix(value);
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int& ele: a) cin >> ele;

    unordered_map<int, int, CustomHash> mark;
    mark[a[0]] = 0;

    for(int i = 1; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int target = x - a[i] - a[j];
            if(mark.count(target)){
                cout << mark[target] + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
        }

        mark[a[i]] = i;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
