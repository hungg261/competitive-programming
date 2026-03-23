#include<bits/stdc++.h>
using namespace std;

const int MAXVAL = 1e6;
int divcnt[MAXVAL + 5];

void compute(){
    for(int i = 1; i <= MAXVAL; ++i){
        for(int j = i; j <= MAXVAL; j += i){
            ++divcnt[j];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;

    compute();
    while(t--){
        int n;
        cin >> n;

        cout << divcnt[n] << '\n';
    }

    return 0;
}
