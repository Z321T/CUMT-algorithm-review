#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 8;
int maxSum;
int board[N][N];
bool column[N], diag1[2 * N], diag2[2 * N];

void backtrack(int row, int currentSum) {
    if (row == N) {
        maxSum = max(maxSum, currentSum);
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (!column[col] && !diag1[row + col] && !diag2[row - col + N]) {
            column[col] = diag1[row + col] = diag2[row - col + N] = true;
            backtrack(row + 1, currentSum + board[row][col]);
            column[col] = diag1[row + col] = diag2[row - col + N] = false;
        }
    }
}

vector<int> solve(vector<vector<int>>& boards) {
    int k = boards.size();
    vector<int> results;
    for (int i = 0; i < k; ++i) {
        copy(&boards[i][0], &boards[i][0] + N * N, &board[0][0]);
        fill(column, column + N, false);
        fill(diag1, diag1 + 2 * N, false);
        fill(diag2, diag2 + 2 * N, false);
        maxSum = 0;
        backtrack(0, 0);
        results.push_back(maxSum);
    }
    return results;
}

int main() {
    int k;
    cin >> k;
    vector<vector<int>> boards(k, vector<int>(64));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 64; ++j) {
            cin >> boards[i][j];
        }
    }
    vector<int> results = solve(boards);
    for (int result : results) {
        cout << result << endl;
    }
    return 0;
}