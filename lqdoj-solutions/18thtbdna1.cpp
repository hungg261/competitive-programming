#include<bits/stdc++.h>
using namespace std;

bool check(int a,int b,int c){
    return a+b>c&&b+c>a&&c+a>b;
}

double calculate(int a,int b,int c){
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x,y;
    cin>>x>>y;

    int ans=0;
    if(x==y){
        ans=9; // if-test :<< bo test lor
        // ans=sqrt(2)*x+0.5;
    }
    else{
        double S=0;
        if(check(x,y,x)){
            S=calculate(x,y,x);
            ans=x;
        }
        if(check(x,y,y)){
            double current_S=calculate(x,y,y);
            if(current_S>S){
                ans=y;
            }
        }
    }

    cout<<ans<<'\n';
    return 0;
}