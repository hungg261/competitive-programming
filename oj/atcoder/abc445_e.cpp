/******************************************************************************
Link: https://atcoder.jp/contests/abc445/tasks/abc445_e
Code: abc445_e
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-14-19.12.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

int powmod(int a, int b, int m){
    a %= m;
    int res = 1;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

struct Pair{
    int first, second;

    Pair(int a = 0, int b = 0): first(a), second(b){}

    void push(int v){
        if(v > first){
            second = first;
            first = v;
        }
        else if(v > second){
            second = v;
        }
    }

    bool operator < (const Pair& other) const{
        return make_pair(first, second) < make_pair(other.first, other.second);
    }
};

const int MAXN = 2e5, MAXVAL = 1e7;
int spf[MAXVAL + 5];

void sieve(){
    for(int i = 2; i * i <= MAXVAL; ++i){
        if(!spf[i]) for(int j = i * i; j <= MAXVAL; j += i){
            spf[j] = spf[j] == 0 ? i : min(spf[j], i);
        }
    }
}

map<int, Pair> mp;
void pfactor(int num){
    while(num > 1){
        int p = spf[num];
        if(p == 0) p = num;

        int cnt = 0;
        while(num % p == 0){
            ++cnt;
            num /= p;
        }
        mp[p].push(cnt);
    }

    if(num > 1){
        mp[num].push(1);
    }
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    mp.clear();
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        pfactor(arr[i]);
    }

    int lcm = 1;
    for(const auto& p: mp){
        lcm = lcm * powmod(p.first, p.second.first, MOD) % MOD;
    }

    for(int i = 1; i <= n; ++i){
        int temp = arr[i];
        int curLCM = lcm;
        while(temp > 1){
            int p = spf[temp];
            if(p == 0) p = temp;

            int cnt = 0;
            while(temp % p == 0){
                ++cnt;
                temp /= p;
            }

            const auto& cur = mp[p];
            if(cnt == cur.first){
                curLCM = curLCM * powmod(powmod(p, cur.first - cur.second, MOD), MOD - 2, MOD) % MOD;
            }
        }

        cout << curLCM << " ";
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    sieve();

    while(t--){
        solve();
    }

    return 0;
}
