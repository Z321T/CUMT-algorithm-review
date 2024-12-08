#include <iostream>
#include <string>

std::string decimalToOctal(int n) {
    std::string octal = "";
    while (n > 0) {
        octal = std::to_string(n % 8) + octal;
        n /= 8;
    }
    return octal;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << decimalToOctal(n) << std::endl;
    return 0;
}