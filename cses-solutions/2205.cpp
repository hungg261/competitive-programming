#include<bits/stdc++.h>
using namespace std;

const int MAXN = 16;
int n;
bool mark[(1 << MAXN) + 1];

void print_binary(int value){
    int cnt = 0;
    while(value > 0){
        cout << (value & 1);
        ++cnt;

        value >>= 1;
    }
    while(cnt < n){
        cout << "0";
        ++cnt;
    }

    cout << '\n';
}

void solve(){
    stack<int> que;
    que.push({0});

    while(!que.empty()){
        int mask = que.top();
        que.pop();


        mark[mask] = true;
        print_binary(mask);

        for(int i = 0; i < n; ++i){
            int new_mask = mask ^ (1 << i);
            if(!mark[new_mask]){
                que.push(new_mask);
                break;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;

    solve();
    return 0;
}
