// De thi pho thong nang khieu 2019-2020: Support 1-1 Le Phi Long gui ngay 8/2/2024
#include <bits/stdc++.h>
using namespace std;

bool checkOut(int x, int y, char c, int n, int m){
    return (x == 0 && c == 'N') || (x == n - 1 && c == 'S') || (y == 0 && c == 'W') || (y == m - 1 && c == 'E');
}

// BFS!
long long solve(string a[], long long n, long long m){
    vector<vector<bool>> check(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(checkOut(i, j, a[i][j], n, m)){
                q.push({i, j});
                check[i][j] = true;
            }
        }
    }
    long long cnt = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        cnt++;
        q.pop();
        if(y - 1 >= 0 && a[x][y - 1] == 'E' && check[x][y - 1] == false){
            q.push({x, y - 1});
            check[x][y - 1] = true;
        }
        if(y + 1 < m && a[x][y + 1] == 'W' && check[x][y + 1] == false){
            q.push({x, y + 1});
            check[x][y + 1] = true;
        }
        if(x - 1 >= 0 && a[x - 1][y] == 'S' && check[x - 1][y] == false){
            q.push({x - 1, y});
            check[x - 1][y] = true;
        }
        if(x + 1 < n && a[x + 1][y] == 'N' && check[x + 1][y] == false){
            q.push({x + 1, y});
            check[x + 1][y] = true;
        }
    }
    return n * m - cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m;
    cin >> n >> m;
    string a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << solve(a, n, m);
    return 0;
}
