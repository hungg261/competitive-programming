#include<bits/stdc++.h>
using namespace std;

int char_to_idx(char c){
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    if(c == 'T') return 3;
    throw "sus";
}

char idx_to_char(int idx){
    for(char c: "ACGT"){
        if(char_to_idx(c) == idx) return c;
    }
    throw "amogus";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;

    int n = s.size();

    vector<vector<int>> next(n + 1, vector<int>(4));
    vector<int> prev = {n + 1, n + 1, n + 1, n + 1};

    for(int i = n; i >= 1; --i){
        next[i] = prev;

        int c = char_to_idx(s[i - 1]);
        prev[c] = i;
    }
    next[0] = prev;

    int idx = 0;
    while(idx <= n){
        auto pos = max_element(begin(next[idx]), end(next[idx]));
        cout << idx_to_char(pos - begin(next[idx]));
        idx = *pos;
    }

//    for(int i = 0; i < 4; ++i){
//        for(int j = 0; j < n; ++j){
//            cerr << next[j][i] << '\t';
//        } cerr << '\n';
//    }

    return 0;
}
