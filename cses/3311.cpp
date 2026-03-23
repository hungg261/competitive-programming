#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500, MAXM= 500;
int n, m;
string a[MAXN + 1];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char cur;
            if((i + j) % 2 == 0){
                cur = a[i][j] == 'A' ? 'B' : 'A';
            }
            else{
                cur = a[i][j] == 'C' ? 'D' : 'C';
            }

            cout << cur;
        }
        cout << '\n';
    }
    return 0;
}
