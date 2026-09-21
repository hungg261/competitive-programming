/******************************************************************************
Link: https://codeforces.com/gym/104150/problem/C
Code: Gym_104150C
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-21-18.29.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6;

const int BASE = 67, MOD = 1e9 + 9;
int hashes[MAXN + 5], powhash[MAXN + 5], n;

string S;
void compute(){
    powhash[0] = 1;
    for(int i = 1; i <= n; ++i){
        hashes[i] = (hashes[i - 1] * BASE + (S[i] - 'a' + 1)) % MOD;
        powhash[i] = powhash[i - 1] * BASE % MOD;
    }
}

int getHash(int l, int r){
    return ((hashes[r] - hashes[l - 1] * powhash[r - l + 1]) % MOD + MOD) % MOD;
}

namespace Solve{

void solve(){
    int i = 1;
    vector<string> res;
    for(int j = 1; j * 2 <= n; ++j){
        int rev_i = n - j + 1, rev_j = n - i + 1;
        if(getHash(i, j) == getHash(rev_i, rev_j)){
            res.push_back(S.substr(i, j - i + 1));
            i = j + 1;
        }
    }

    cout << (int)res.size() << "\n";
    for(const string& s: res){
        cout << s << "\n";
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> S;
    n = S.size();
    S = "#" + S;

    compute();

    Solve::solve();

    return 0;
}
