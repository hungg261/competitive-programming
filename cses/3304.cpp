#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5, MAXK = 17;
int nxt[MAXN + 5][MAXK + 1];
int arr[MAXN + 5], n;

int R[MAXN + 5];
void compute(){
    vector<int> sta;
    for(int i = n; i >= 1; --i){
        while(!sta.empty() && arr[sta.back()] <= arr[i]) sta.pop_back();
        R[i] = sta.empty() ? n + 1 : sta.back();
        nxt[i][0] = R[i];

        sta.push_back(i);
    }


    for(int k = 1; k <= MAXK; ++k){
        for(int i = 1; i <= n; ++i){
            nxt[i][k] = n + 1;
        }
    }
    for(int k = 1; k <= MAXK; ++k){
        for(int i = 1; i + (1 << k) - 1 <= n; ++i){
            nxt[i][k] = nxt[i][k - 1] <= n ? nxt[nxt[i][k - 1]][k - 1] : n + 1;
        }
    }
}

int jump(int idx, int steps){
    if(idx + steps > n) return n + 1;

    for(int bit = 0; steps > 0 && 1 <= idx && idx <= n; ++bit, steps >>= 1){
        if(steps & 1) idx = nxt[idx][bit];
    }
    return idx;
}

int get(int u, int v){
    int l = 1, r = n - u + 1, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(jump(u, mid) > v){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    compute();
    while(q--){
        int a, b;
        cin >> a >> b;

        cout << get(a, b) << '\n';
    }

    return 0;
}
