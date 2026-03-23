#include<bits/stdc++.h>
using namespace std;

struct Element{
    int value, idx;

    bool operator < (const Element& other) const{
        return this->value < other.value;
    }

    operator int(){ return this->value; }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;

    vector<Element> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i].value;

        arr[i].idx = i;
    }
    sort(begin(arr), end(arr));

    for(int i = 1; i <= n; ++i){
        int target = x - arr[i];

        auto pos = lower_bound(begin(arr) + 1, begin(arr) + i, target);

        if(pos != begin(arr) + i && *pos == target){
            cout << (*pos).idx << ' ' << arr[i].idx << '\n';
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
