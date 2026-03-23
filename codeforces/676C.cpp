#include<bits/stdc++.h>
using namespace std;

int n, k;
string S;

int solve(char c){
    int i = 1, modified = 0;
    int ans = 0;
    for(int j = 1; j <= n; ++j){
        if(S[j] != c){
            ++modified;
        }

        while(modified > k){
            if(S[i] != c) --modified;
            ++i;
        }

        ans = max(ans, j - i + 1);
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> S;
    S = "#" + S;

    cout << max(solve('a'), solve('b')) << '\n';

    return 0;
}
