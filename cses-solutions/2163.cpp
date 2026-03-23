#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    ordered_set s;
    for(int i = 1; i <= n; ++i) s.insert(i);

    int cur = 0;
    int sz = n;
    while(sz > 0){
        cur = (cur + k) % sz + 1;
        auto pos = s.find_by_order(cur - 1);

        cout << *pos << ' ';

        s.erase(pos);
        --cur; --sz;
    }

    return 0;
}
