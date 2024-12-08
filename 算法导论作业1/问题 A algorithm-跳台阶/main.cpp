#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int n;
    std::vector<int> dp(101, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= 100; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    while (std::cin >> n) {
        std::cout << dp[n] << std::endl;
    }

    return 0;
}