#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 20;
int fact[MAX + 1];
void compute(){
    fact[0] = 1;
    for(int i = 1; i <= MAX; ++i){
        fact[i] = fact[i - 1] * i;
    }
}

void solve1(){
    int n, k;
    cin >> n >> k;

    bool mark[n + 1] = {};
    auto next_num = [&mark, &n](int idx){
        for(int c = 1; c <= n; ++c){
            if(!mark[c]){
                --idx;
                if(idx == 0) return c;
            }
        }

        return 0LL;
    };

    int res[n + 1];
    for(int i = 1; i <= n; ++i){
        int thu_tu = (k - 1) / fact[n - i] + 1;
        k = (k - 1) % fact[n - i] + 1;

        res[i] = next_num(thu_tu);
        mark[res[i]] = true;
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i] << ' ';
    } cout << '\n';
}

void solve2(){
    int n; cin >> n;
    int arr[n + 1]; for(int i = 1; i <= n; ++i) cin >> arr[i];

    bool mark[n + 1] = {};
    auto get_pos = [&mark, &n](int c){
        int pos = 0;
        for(int ch = c; ch >= 1; --ch){
            if(!mark[ch]){
                ++pos;
            }
        }

        return pos;
    };

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += (get_pos(arr[i]) - 1) * fact[n - i];

        mark[arr[i]] = true;
    }

    cout << ans + 1 << '\n';
}

void init(){
    int type; cin >> type;
    if(type == 1) solve1();
    else solve2();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    compute();
    while(t--){
        init();
    }

    return 0;
}
