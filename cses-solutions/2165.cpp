/******************************************************************************
Link: https://cses.fi/problemset/task/2165
Code: 2165
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-18-00.07.12
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

void hanoi(int n,int from,int to,int left){
    if(n==0){
        return;
    }

    hanoi(n-1,from,left,to);
    cout<<from<<' '<<to<<'\n';
    hanoi(n-1,left,to,from);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("2165.INP","r",stdin);
    //freopen("2165.OUT","w",stdout);
    int n;
    cin>>n;

    cout<<(1<<n)-1<<'\n';
    hanoi(n,1,3,2);
    return 0;
}
