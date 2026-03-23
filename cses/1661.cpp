#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Element{
    int value, idx;

    static int lower_bound(const vector<Element>& arr, int l, int r, int target){
        int idx = r + 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(arr[mid] >= target){
                idx = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return idx;
    }

    static int upper_bound(const vector<Element>& arr, int l, int r, int target){
        int idx = r + 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(arr[mid] > target){
                idx = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return idx;
    }

    static pair<int, int> equal_range(const vector<Element>& arr, int l, int r, int target){
        return {lower_bound(arr, l, r, target), upper_bound(arr, l, r, target) - 1};
    }

    bool operator < (const Element& other) const{
        if(this->value == other.value) return this->idx < other.idx;
        return this->value < other.value;
    }

    operator int() const{
        return this->value;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;

    vector<Element> prefix(n + 1);
    prefix[0] = {0, 0};

    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        prefix[i] = {prefix[i - 1] + cur, i};
    }
    sort(begin(prefix), end(prefix));

    long long ans = 0;
    for(int i = 0; i <= n; ++i){
        int l, r, target = prefix[i] - x;
        tie(l, r) = Element::equal_range(prefix, 0, n, target);

        int idx = l - 1, left = l;
        while(l <= r){
            int mid = (l + r) / 2;
            if(prefix[mid].idx < prefix[i].idx){
                idx = mid;
                l = mid + 1;
            }
            else r = mid -1;
        }

        ans += idx - left + 1;
    }

    cout << ans << '\n';

    return 0;
}
