#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int res[MAXN + 5];
vector<int> children[MAXN + 5];

void dfs(int parent){
    for(int child: children[parent]){
        dfs(child);

        res[parent] += res[child] + 1;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;

    for(int i = 2; i <= n; ++i){
        int boss;
        cin >> boss;

        children[boss].push_back(i);
    }

    dfs(1);

    for(int i = 1; i <= n; ++i){
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}
