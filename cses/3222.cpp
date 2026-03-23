#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e7;
int arr[MAXN + 5], n, k;

int temp[MAXN + 5];
void compress(){
    for(int i = 1; i <= n; ++i) temp[i] = arr[i];
    sort(temp + 1, temp + n + 1);

    for(int i = 1; i <= n; ++i){
        arr[i] = lower_bound(temp + 1, temp + n + 1, arr[i]) - temp;
    }
}

int mark[MAXN + 5], cur = 0;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    compress();

    for(int i = 1; i < k; ++i) if(mark[arr[i]]++ == 0) ++cur;

    for(int j = k; j <= n; ++j){
        if(--mark[arr[j - k]] == 0) --cur;
        if(mark[arr[j]]++ == 0) ++cur;

        cout << cur << ' ';
    }

    return 0;
}
