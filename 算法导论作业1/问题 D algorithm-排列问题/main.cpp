#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void permute(std::string str, int l, int r, std::set<std::string>& result) {
    if (l == r) {
        result.insert(str);
    } else {
        for (int i = l; i <= r; i++) {
            std::swap(str[l], str[i]);
            permute(str, l + 1, r, result);
            std::swap(str[l], str[i]); // backtrack
        }
    }
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    input.pop_back(); // remove the trailing comma

    std::set<std::string> result;
    permute(input, 0, input.size() - 1, result);

    for (const auto& perm : result) {
        std::cout << perm << " ";
    }
    std::cout << std::endl;

    return 0;
}