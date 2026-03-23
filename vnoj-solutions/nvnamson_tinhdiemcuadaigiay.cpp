// [!] DeepSeek R1 - Demo
//
//
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 10007;

struct Group {
    vector<pair<int, int>> even;
    vector<pair<int, int>> odd;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }

    unordered_map<int, Group> color_map;

    for (int i = 0; i < n; ++i) {
        int color = colors[i];
        int idx = i + 1;
        int num = numbers[i];
        if (idx % 2 == 0) {
            color_map[color].even.emplace_back(idx, num);
        } else {
            color_map[color].odd.emplace_back(idx, num);
        }
    }

    long long total = 0;

    for (auto &entry : color_map) {
        auto &group = entry.second;

        vector<vector<pair<int, int>>> subgroups = {group.even, group.odd};

        for (auto &subgroup : subgroups) {
            int k = subgroup.size();
            if (k < 2) continue;

            vector<long long> x, a;
            for (auto &p : subgroup) {
                x.push_back(p.first);
                a.push_back(p.second);
            }

            vector<long long> prefix_x(k + 1, 0), prefix_a(k + 1, 0);
            for (int i = 0; i < k; ++i) {
                prefix_x[i + 1] = prefix_x[i] + x[i];
                prefix_a[i + 1] = prefix_a[i] + a[i];
            }

            long long term1 = 0, term2 = 0, term3 = 0, term4 = 0;

            // Term1: sum x[i] * a[i] * (k - 1 - i)
            for (int i = 0; i < k - 1; ++i) {
                term1 += x[i] * a[i] % MOD * (k - 1 - i) % MOD;
                term1 %= MOD;
            }

            // Term4: sum x[j] * a[j] * j
            for (int j = 1; j < k; ++j) {
                term4 += x[j] * a[j] % MOD * j % MOD;
                term4 %= MOD;
            }

            // Term2: sum a[j] * prefix_x[j]
            for (int j = 1; j < k; ++j) {
                term2 += a[j] * (prefix_x[j] % MOD) % MOD;
                term2 %= MOD;
            }

            // Term3: sum x[j] * prefix_a[j]
            for (int j = 1; j < k; ++j) {
                term3 += x[j] * (prefix_a[j] % MOD) % MOD;
                term3 %= MOD;
            }

            long long sum = (term1 + term2 + term3 + term4) % MOD;
            total = (total + sum) % MOD;
        }
    }

    cout << total % MOD << endl;

    return 0;
}
