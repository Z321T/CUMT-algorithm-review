#include <iostream>
#include <string>
using namespace std;

string decryptCaesarCipher(const string &cipherText, int k) {
    string plainText = cipherText;
    k = k % 26; // 处理偏移量超过26的情况
    if (k < 0) {
        k += 26; // 处理负偏移量
    }

    for (char &c : plainText) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base - k + 26) % 26 + base;
        }
    }
    return plainText;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        int k;
        cin >> S >> k;
        cout << decryptCaesarCipher(S, k) << endl;
    }
    return 0;
}