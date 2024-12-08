#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 判断一个数是否为素数
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void backtrack(vector<int>& ring, vector<bool>& used, int n, int& count) {
    if (ring.size() == n) {
        if (isPrime(ring.back() + ring[0])) {
            ++count;
        }
        return;
    }

    for (int i = 2; i <= n; ++i) {
        if (!used[i] && isPrime(ring.back() + i)) {
            used[i] = true;
            ring.push_back(i);
            backtrack(ring, used, n, count);
            ring.pop_back();
            used[i] = false;
        }
    }
}

int countPrimeRings(int n) {
    vector<int> ring = {1};
    vector<bool> used(n + 1, false);
    used[1] = true;
    int count = 0;
    backtrack(ring, used, n, count);
    return count;
}

int main() {
    int n;
    while (cin >> n) {
        cout << countPrimeRings(n) << endl;
    }
    return 0;
}