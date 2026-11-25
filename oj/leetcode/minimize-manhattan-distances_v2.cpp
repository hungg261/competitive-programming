/******************************************************************************
Link: https://leetcode.com/problems/minimize-manhattan-distances/description
Code: minimize-manhattan-distances
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-25-10.44.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct TwoBig{
    int b1, b2, s1, s2;

    TwoBig(){
        b1 = b2 = -INF;
        s1 = s2 = INF;
    }

    void insert(int x){
        if(x >= b1){
            b2 = b1;
            b1 = x;
        }
        else if(x >= b2){
            b2 = x;
        }

        if(x <= s1){
            s2 = s1;
            s1 = x;
        }
        else if(x <= s2){
            s2 = x;
        }
    }

    int get(int x){
        return (x != b1 ? b1 : b2) - (x != s1 ? s1 : s2);
    }
};

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        TwoBig ms[4];

        int n = points.size();
        for(int mask = 0; mask < 4; ++mask){
            for(int i = 0; i < n; ++i){
                int cur = 0;
                if(mask & 1) cur += points[i][0];
                else cur -= points[i][0];
                if(mask & 2) cur += points[i][1];
                else cur -= points[i][1];

                ms[mask].insert(cur);
            }
        }

        int ans = INF;
        for(int i = 0; i < n; ++i){
            int res = 0;
            for(int mask = 0; mask < 4; ++mask){
                int cur = 0;
                if(mask & 1) cur += points[i][0];
                else cur -= points[i][0];
                if(mask & 2) cur += points[i][1];
                else cur -= points[i][1];

                res = max(res, ms[mask].get(cur));
            }
            ans = min(ans, res);
        }

        return ans;
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> pts(n, vector<int>(2));
    for(int i = 0; i < n; ++i){
        cin >> pts[i][0] >> pts[i][1];
    }

    cout << Solution().minimumDistance(pts);

    return 0;
}
#endif // __________
