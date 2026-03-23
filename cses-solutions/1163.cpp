#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, n;
    cin >> x >> n;

    multiset<int> lights, dist;
    lights.insert(0); lights.insert(x);
    dist.insert(x);

    while(n--){
        int ele; cin >> ele;

        auto left = lights.upper_bound(ele), right = left;
        --left;

        dist.erase(dist.find(*right - *left));
        dist.insert(ele - *left); dist.insert(*right - ele);
        lights.insert(ele);

        cout << *dist.rbegin() << ' ';
    }
    cout << '\n';

    return 0;
}
