#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <functional> // Add this header

using namespace std;

// 定义哈夫曼树节点
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;
    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// 比较器，用于优先队列
struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq;
    }
};

// 计算哈夫曼编码长度
int calculateHuffmanLength(const string& str) {
    if (str.empty()) return 0;

    // 计算字符频率
    unordered_map<char, int> freqMap;
    for (char ch : str) {
        freqMap[ch]++;
    }

    // 构建优先队列
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (auto& pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // 构建哈夫曼树
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* newNode = new HuffmanNode('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    // 计算哈夫曼编码长度
    HuffmanNode* root = pq.top();
    int totalLength = 0;
    function<void(HuffmanNode*, int)> calculateLength = [&](HuffmanNode* node, int depth) {
        if (!node) return;
        if (!node->left && !node->right) {
            totalLength += node->freq * depth;
        }
        calculateLength(node->left, depth + 1);
        calculateLength(node->right, depth + 1);
    };
    calculateLength(root, 0);

    return totalLength;
}

int main() {
    int T;
    cin >> T;
    vector<string> strings(T);
    for (int i = 0; i < T; ++i) {
        cin >> strings[i];
    }

    for (const string& str : strings) {
        cout << calculateHuffmanLength(str) << endl;
    }

    return 0;
}