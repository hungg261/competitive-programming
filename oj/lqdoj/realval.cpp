#include<bits/stdc++.h>
#define int long long
using namespace std;

int digit_sum(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int RealValue(int n){
    if(n<=5){
        return n;
    }

    return RealValue(digit_sum(n)/2);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;

    cout<<RealValue(n)<<'\n';
    return 0;
}