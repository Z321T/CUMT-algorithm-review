#include <iostream>
#include <vector>

const int MOD = 100000007;

// Example function f(x) = x^2
int f(int x) {
    return (x * x) % MOD;
}

int main() {
    int x;
    std::vector<int> results;

    while (std::cin >> x) {
        results.push_back(f(x));
    }

    for (int result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}