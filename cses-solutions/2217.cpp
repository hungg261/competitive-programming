#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

int sim[6];
int arr[MAXN + 5], mark[MAXN + 5];

bool cmp(const int& u, const int& v){
    return mark[u] < mark[v];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];

        mark[i] = n + 2;
    }
    mark[n] = mark[n + 1] = n + 2;

    int ans = 0;

    for(int i = 0; i < n; ++i){
        if(mark[arr[i] - 1] > i) ++ans;
        mark[arr[i]] = i;
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        --a; --b;


        int diff = abs(arr[a] - arr[b]);
        int sz = diff == 1 ? 4 : diff == 2 ? 5 : 6;
        if(sz == 4){
            int v_a = min(arr[a], arr[b]), v_b = max(arr[a], arr[b]);

            sim[0] = v_a - 1; sim[1] = v_a;
            sim[2] = v_b; sim[3] = v_b + 1;
        }
        else if(sz == 5){
            int v_a = min(arr[a], arr[b]), v_b = max(arr[a], arr[b]);

            sim[0] = v_a - 1; sim[1] = v_a; sim[2] = v_a + 1;
            sim[3] = v_b; sim[4] = v_b + 1;
        }
        else{
            sim[0] = arr[a] - 1; sim[1] = arr[a]; sim[2] = arr[a] + 1;
            sim[3] = arr[b] - 1; sim[4] = arr[b]; sim[5] = arr[b] + 1;
        }

        for(int i = 0; i < sz; ++i){
            if(mark[sim[i] - 1] > mark[sim[i]]) --ans;
        }

        mark[arr[a]] = b; mark[arr[b]] = a;
        swap(arr[a], arr[b]); swap(a, b);

        for(int i = 0; i < sz; ++i){
            if(mark[sim[i] - 1] > mark[sim[i]]) ++ans;
        }

        cout << ans << '\n';
    }

    return 0;
}
