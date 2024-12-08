#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Cow {
    double position;
    double weight;
};

bool compareByPosition(const Cow &a, const Cow &b) {
    return a.position < b.position;
}

int main() {
    int Ca;
    std::cin >> Ca;
    for (int c = 1; c <= Ca; ++c) {
        int n;
        std::cin >> n;
        std::vector<Cow> cows(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> cows[i].position >> cows[i].weight;
        }

        // 按位置排序
        std::sort(cows.begin(), cows.end(), compareByPosition);

        // 计算总权重
        double totalWeight = 0;
        for (const auto &cow : cows) {
            totalWeight += cow.weight;
        }

        // 找到加权中位数
        double cumulativeWeight = 0;
        double medianPosition = 0;
        for (const auto &cow : cows) {
            cumulativeWeight += cow.weight;
            if (cumulativeWeight >= totalWeight / 2) {
                medianPosition = cow.position;
                break;
            }
        }

        // 计算总消极情绪
        double totalNegativeImpact = 0;
        for (const auto &cow : cows) {
            double distance = std::abs(cow.position - medianPosition);
            totalNegativeImpact += std::pow(distance, 3) * cow.weight;
        }

        // 输出结果，四舍五入为整数
        std::cout << "Case #" << c << ": " << std::round(totalNegativeImpact) << std::endl;
    }

    return 0;
}