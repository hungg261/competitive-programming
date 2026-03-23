#include<bits/stdc++.h>
using namespace std;

int Search(const string& S){
    int sz = S.size();
    for(int i = 1; i < sz; ++i){
        if(S[i - 1] == S[i]) return i;
    }

    return -1;
}

char NOT(char c){
    return c == '0' ? '1' : '0';
}

void flip(string& S, int l, int r){
    for(int i = l; i <= r; ++i){
        S[i] = NOT(S[i]);
    }
}

int farthestRight(const string& S, int idx){
    int i;
    for(i = idx + 1; i < (int)S.size(); ++i){
        if(S[idx] != S[i]) break;
    }

    return i - 1;
}

int farthestLeft(const string& S, int idx){
    int i;
    for(i = idx - 1; i >= 0; --i){
        if(S[idx] != S[i]) break;
    }

    return i + 1;
}

vector<pair<int, int>> subsolve(string S){
    vector<pair<int, int>> res;

    int l, r = Search(S);
    if(r == -1){ flip(S, 1, 3); r = 1; res.emplace_back(1, 3); }
    l = r - 1;

    int sz = S.size();
    char c = S[r];

    while(r + 1 < sz){
        if(S[r + 1] == c){
            r = farthestRight(S, r + 1);
        }
        else{
            res.emplace_back(l, r);
            r = farthestRight(S, r + 1);

            c = NOT(c);
        }
    }


    while(l - 1 >= 0){
        if(S[l - 1] == c){
            l = farthestLeft(S, l - 1);
        }
        else{
            res.emplace_back(l, r);
            l = farthestLeft(S, l - 1);

            c = NOT(c);
        }
    }

    if(c == '1') res.emplace_back(l, r);
    return res;
}

void solve(){
    int n;
    cin >> n;

    string S, T;
    cin >> S >> T;

    vector<pair<int, int>> res1 = subsolve(S), res2 = subsolve(T);
    int ans = res1.size() + res2.size();

    cout << ans << '\n';

    for(const pair<int, int>& p: res1) cout << p.first + 1 << ' ' << p.second + 1 << '\n';

    reverse(begin(res2), end(res2));
    for(const pair<int, int>& p: res2) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
