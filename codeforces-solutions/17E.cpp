/******************************************************************************
Link: https://codeforces.com/problemset/problem/17/E
Code: 17E
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-19-13.06.53
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 51123987, INV2 = 25561994;
const int MAXN = 2e6;
int n;
string s;
int P[MAXN * 2 + 5];

int St[MAXN + 5], En[MAXN + 5];

void solve(){
    string temp = "^#";
    for(char c: s){
        temp += c;
        temp += '#';
    }
    temp += "$";

    int sz = temp.size();
    int C = 0, R = 0;

    int total = 0;
    for(int i = 0; i < sz; ++i){
        int mirror = C * 2 - i;

        if(i < R) P[i] = min(R - i, P[mirror]);

        while(temp[i + P[i] + 1] == temp[i - P[i] - 1])
            ++P[i];

        if(i + P[i] > R){
            C = i;
            R = i + P[i];
        }

        int idx = i / 2 - 1;
        int rad = (P[i] + 1) / 2;

        if(2 <= i && i < sz - 2){
            St[max(0LL, idx - rad + 1)]++;
            St[idx + 1]--;

            if(temp[i] == '#'){
                En[idx + 1]++;
                En[min(n + 1, idx + rad + 1)]--;
            }
            else{
                En[idx]++;
                En[min(n + 1, idx + rad)]--;
            }

//            cerr << i << " " << temp[i] << " " << idx << " " << rad << "\n";
        }

    }

    for(int i = 1; i <= n + 1; ++i){
        St[i] += St[i - 1];
        En[i] += En[i - 1];

        St[i] %= MOD;
        En[i] %= MOD;

        total += St[i];
        total %= MOD;
    }

    for(int i = n + 1; i >= 0; --i)
        (St[i] += St[i + 1]) %= MOD;

    int res = 0;
    for(int i = 0; i <= n; ++i){
        res += 1LL * En[i] * St[i + 1];
        res %= MOD;

//        cerr << i << " " << St[i] << " " << En[i] << "\n";
    }

//    cerr << total << " " << res << "\n";

    total = 1LL * total % MOD * (total - 1) % MOD * INV2 % MOD;
    cout << ((total - res) % MOD + MOD) % MOD << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> s;

//    n = 2e6;
//    s = string(n, 'a');

    solve();

    return 0;
}
