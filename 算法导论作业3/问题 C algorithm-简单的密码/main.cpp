#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<long long> dp(n + 1, 0);
        if (n >= 3) {
            dp[3] = 1;
            for (int i = 4; i <= n; ++i) {
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + pow(2, i-3);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}