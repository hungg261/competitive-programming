#include<bits/stdc++.h>
#define int long long
using namespace std;

pair<vector<int>, vector<int>> compute(string s, int BASE, int MOD){
    int n = s.size();
    s = '#' + s;

    vector<int> gethash(n + 1), powhash(n + 1);

    gethash[0] = 0;
    powhash[0] = 1 % MOD;
    for(int i = 1; i <= n; ++i){
        gethash[i] = (gethash[i - 1] * BASE + (s[i] - 'a' + 1)) % MOD;
        powhash[i] = powhash[i - 1] * BASE % MOD;
    }

    return make_pair(gethash, powhash);
}

int getHash(const vector<int>& gethash, const vector<int>& powhash, int l, int r, int MOD){
    return ((gethash[r] - gethash[l - 1] * powhash[r - l + 1]) % MOD + MOD) % MOD;
}


const int BASE = 29, MOD = 1e9 + 9;
vector<int> gethash, powhash;
vector<int> rev_gethash, rev_powhash;

int chan[2], le[2] = {0, 0};

bool check_palindrome(int l, int r, int n){
    int current_hash = getHash(gethash, powhash, l, r, MOD);

    int rev_l = n - l + 1, rev_r = n - r + 1;
    int rev_hash = getHash(rev_gethash, rev_powhash, rev_r, rev_l, MOD);

    return current_hash == rev_hash;
}

bool check(int length, int n){
    for(int i = length; i <= n; ++i){
        if(check_palindrome(i - length + 1, i, n)){
            if(length % 2 == 0){
                chan[0] = i - length;
                chan[1] = i - 1;
            }
            else{
                le[0] = i - length;
                le[1] = i - 1;
            }
            return true;
        }
    }

    return false;
}

int solve_chan(int n){
    int ans = 1;
    int l = 1, h = n / 2;
    while(l <= h){
        int mid = (l + h) / 2;
        if(check(mid * 2, n)){
            ans = mid * 2;
            l = mid + 1;
        }
        else h = mid - 1;
    }

    return ans;
}

int solve_le(int n){
    int ans = 1;
    int l = 1, h = (n + 1) / 2;
    while(l <= h){
        int mid = (l + h) / 2;
        if(check(mid * 2 - 1, n)){
            ans = mid * 2 - 1;
            l = mid + 1;
        }
        else h = mid - 1;
    }

    return ans;
}

void solve(const string& s, int n){
    int res_chan = solve_chan(n);
    int res_le = solve_le(n);

    if(res_chan > res_le){
        cout << s.substr(chan[0], chan[1] - chan[0] + 1) << '\n';
    }
    else{
        cout << s.substr(le[0], le[1] - le[0] + 1) << '\n';
    }
}

void init(const string& s, int n){
    solve(s, n);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;

    string rev_s = s;
    reverse(begin(rev_s), end(rev_s));

    tie(gethash, powhash) = compute(s, BASE, MOD);
    tie(rev_gethash, rev_powhash) = compute(rev_s, BASE, MOD);

    int n = s.size();
    init(s, n);

    return 0;
}
