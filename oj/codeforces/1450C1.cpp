/******************************************************************************
Link: https://codeforces.com/contest/1450/problem/C1
Code: 1450C1
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-11-09.39.41
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// failed
// WA test case:

/*
1
5
XXXXX
XXX..
X..XX
XXXXX
XXXXX
===
WA output:

XXOXX
XXO..
O..XX
XXOXX
XXOOO
  ^^^
*/

void brute(){
    int n;
    cin >> n;

    vector<string> T(n);
    for(int i = 0; i < n; ++i){
        cin >> T[i];
    }

    auto get = [&](){
        pair<int, pair<int, int>> best = {-1, {}};
        vector<vector<int>> freq(n, vector<int>(n, 0));
        for(int x = 0; x < n; ++x){
            for(int y = 0; y < n; ++y){
                if(T[x][y] == '.') continue;

                if(0 < x && x < n - 1 && T[x - 1][y] == T[x][y] && T[x][y] == T[x + 1][y])
                    ++freq[x - 1][y], ++freq[x][y], ++freq[x + 1][y];
                if(0 < y && y < n - 1 && T[x][y - 1] == T[x][y] && T[x][y] == T[x][y + 1])
                    ++freq[x][y - 1], ++freq[x][y], ++freq[x][y + 1];
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(T[i][j] == '.') continue;
                best = max(best, {freq[i][j], {i, j}});
            }
        }
        return best;
    };

    pair<int, pair<int, int>> best;
    while(true){
        best = get();
        if(best.first <= 0) break;

        int x, y; tie(x, y) = best.second;
        T[x][y] = 'O';
    }

    cerr << endl;

    for(int i = 0; i < n; ++i)
        cout << T[i] << "\n";
}

void solve(){
    int n;
    cin >> n;

    vector<string> T(n);
    for(int i = 0; i < n; ++i){
        cin >> T[i];
    }

    set<pair<int, pair<int, int>>, greater<>> S;
    vector<vector<int>> freq(n, vector<int>(n, 0));
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < n; ++y){
            if(T[x][y] == '.') continue;

            if(0 < x && x < n - 1 && T[x - 1][y] == T[x][y] && T[x][y] == T[x + 1][y])
                ++freq[x - 1][y], ++freq[x][y], ++freq[x + 1][y];
            if(0 < y && y < n - 1 && T[x][y - 1] == T[x][y] && T[x][y] == T[x][y + 1])
                ++freq[x][y - 1], ++freq[x][y], ++freq[x][y + 1];
        }
    }
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < n; ++y){
            S.insert({freq[x][y], {x, y}});

//            cerr << freq[x][y] << " ";
        }
//        cerr << endl;
    }

    while(!S.empty()){
        pair<int, pair<int, int>> best = *S.begin();
        if(best.first == 0) break;

        int x, y; tie(x, y) = best.second;
//        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cerr << freq[i][j] << " \n"[j == n - 1];

        for(int i = max(1, x - 1); i <= min(n - 2, x + 1); ++i){
            if(T[i - 1][y] == T[i][y] && T[i][y] == T[i + 1][y]){
//                cerr << "up0: " << i << " " << y << endl;

                {
                    auto it = S.find({freq[i - 1][y]--, {i - 1, y}});
                    S.erase(it); // cerr << (it == S.end()) << endl;
                    S.insert({freq[i - 1][y], {i - 1, y}});
                }

                {
                    auto it = S.find({freq[i][y]--, {i, y}});
                    S.erase(it); // cerr << (it == S.end()) << endl;
                    S.insert({freq[i][y], {i, y}});
                }

                {
                    auto it = S.find({freq[i + 1][y]--, {i + 1, y}});
                    S.erase(it); // cerr << (it == S.end()) << endl;
                    S.insert({freq[i + 1][y], {i + 1, y}});
                }
            }
        }

        for(int j = max(1, y - 1); j <= min(n - 2, y + 1); ++j){
            if(T[x][j - 1] == T[x][j] && T[x][j] == T[x][j + 1]){
//                cerr << "up1: " << x << " " << j << endl;

                {
                    auto it = S.find({freq[x][j - 1]--, {x, j - 1}});
                    S.erase(it); // cerr << (it == S.end()) << endl;
                    S.insert({freq[x][j - 1], {x, j - 1}});
                }

                {
                    auto it = S.find({freq[x][j]--, {x, j}});
                    S.erase(it); // cerr << (it == S.end()) << endl;
                    S.insert({freq[x][j], {x, j}});
                }

                {
                    auto it = S.find({freq[x][j + 1]--, {x, j + 1}});
                    S.erase(it); // cerr << (it == S.end()) << endl;
                    S.insert({freq[x][j + 1], {x, j + 1}});
                }
            }
        }

        T[x][y] = 'O';

//        for(auto z: S) cerr << "S: " << z.first << " | " << z.second.first << " " << z.second.second << "\n";
//        for(int i = 0; i < n; ++i) cerr << T[i] << "\n"; system("pause");
    }

    for(int i = 0; i < n; ++i)
        cout << T[i] << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
