#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXLG = __lg(MAXN) + 1;
int n, m, arr[MAXN + 5];
pair<int, int> table[2][MAXN + 5][MAXLG + 5];

void compute(){
    for(int i = 1; i <= n; ++i){
        table[0][i][0] = table[1][i][0] = {arr[i], i};
    }

    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            table[0][i][j] = min(table[0][i][j - 1], table[0][i + (1 << j - 1)][j - 1]);
            table[1][i][j] = max(table[1][i][j - 1], table[1][i + (1 << j - 1)][j - 1]);
        }
    }
}

pair<int, int> query(int l, int r){
    int bit = __lg(r - l + 1);
    return {
        min(table[0][l][bit], table[0][r - (1 << bit) + 1][bit]).second,
        max(table[1][l][bit], table[1][r - (1 << bit) + 1][bit]).second
    };
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    compute();

    while(m--){
        int l, r, x;
        cin >> l >> r >> x;

        int minIdx, maxIdx;
        tie(minIdx, maxIdx) = query(l, r);

        if(arr[minIdx] == arr[maxIdx]){
            if(x == arr[minIdx]){
                cout << "-1\n";
                continue;
            }

            cout << l << '\n';
        }
        else if(x == arr[minIdx]){
            cout << maxIdx << '\n';
        }
        else if(x == arr[maxIdx]){
            cout << minIdx << '\n';
        }
        else cout << minIdx << '\n';
    }

    return 0;
}
