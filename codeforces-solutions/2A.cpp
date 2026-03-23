#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<string> names(n);
    vector<int> scores(n);
    map<string, int> totalPoints;

    for (int i = 0; i < n; ++i) {
        cin >> names[i] >> scores[i];
        totalPoints[names[i]] += scores[i];
    }

    int maxPoints = INT_MIN;
    for (const auto &p : totalPoints) {
        maxPoints = max(maxPoints, p.second);
    }

    set<string> candidates;
    for (const auto &p : totalPoints) {
        if (p.second == maxPoints) {
            candidates.insert(p.first);
        }
    }

    if (candidates.size() == 1) {
        cout << *candidates.begin() << '\n';
        return;
    }

    map<string, int> cumulative;
    for (int i = 0; i < n; ++i) {
        cumulative[names[i]] += scores[i];
        if (cumulative[names[i]] >= maxPoints && candidates.count(names[i])) {
            cout << names[i] << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}
