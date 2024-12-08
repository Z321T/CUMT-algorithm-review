#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // 包含INT_MAX

using namespace std;

int main() {
    vector<int> cost(10);
    for (int i = 0; i < 10; ++i) {
        cin >> cost[i];
    }
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (i >= j) {
                dp[i] = min(dp[i], dp[i - j] + cost[j - 1]);
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}