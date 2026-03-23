#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n;

long long BIT[MAXN + 5];
void update(int idx, int value){
    while(idx <= n){
        BIT[idx] += value;
        idx += idx & (-idx);
    }
}

long long get(int idx){
    long long ans = 0;
    while(idx > 0){
        ans += BIT[idx];
        idx -= idx & (-idx);
    }

    return ans;
}

void increase(int l, int r, int x){
    update(l, x);
    update(r + 1, -x);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q;
    cin >> n >> q;

    int prev = 0;
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;
        update(i, cur - prev);

        prev = cur;
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int a, b, u;
            cin >> a >> b >> u;

            increase(a, b, u);
        }
        else{
            int k;
            cin >> k;

            cout << get(k) << '\n';
        }
    }
    return 0;
}
