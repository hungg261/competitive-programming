#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 4e5, MAXK = __lg(MAXN) + 1;
int n, k, arr[MAXN + 5], table[MAXN + 5][MAXK + 5];

void compute(){
    for(int K = 1; K <= MAXK; ++K){
        for(int i = 1; i <= n * 2; ++i){
            table[i][K] = table[table[i][K - 1]][K - 1];
        }
    }
}

int jump(int pos, int steps){
    for(int bit = MAXK; bit >= 0; --bit){
        if(steps >> bit & 1){
            pos = table[pos][bit];
        }
    }

    return pos;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        arr[i + n] = arr[i];
    }

    int j = 1, sum = 0;
    for(int i = 1; i < n * 2; ++i){
        while(j < n * 2 && j - i < n && sum + arr[j] <= k){
            sum += arr[j];
            ++j;
        }

        table[i][0] = j;
        sum -= arr[i];

        // cerr << i << ' ' << j << '\n';
    }
    table[n * 2][0] = n * 2;

    compute();

    int ans = 1e18;
    for(int i = 1; i <= n; ++i){
        int pos = i, res = 0;
        for(int bit = MAXK; bit >= 0; --bit){
            if(table[pos][bit] <= i + n - 1){
                pos = table[pos][bit];
                res += 1 << bit;
            }
        }
        
        ans = min(ans, res + 1);
        // cerr << i << ' ' << res << " | " << pos << '\n';
    }

    cout << ans << '\n';

    return 0;
}