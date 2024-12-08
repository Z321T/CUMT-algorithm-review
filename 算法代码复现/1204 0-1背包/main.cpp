#include <iostream>
using namespace std;

void Knapsack(int n, int *W, int *V, int C, int **m){
    for(int i=0; i<=C; i++){
        if(i<W[n-1])
            m[n-1][i] = 0;
        else
            m[n-1][i] = V[n-1];
    }

    for(int i=n-2; i>0; i--){
        for(int j=0; j<=C; j++){
            if(j<W[i])
                m[i][j] = m[i+1][j];
            else
                m[i][j] = max(m[i+1][j], m[i+1][j-W[i]]+V[i]);
        }
    }

    m[0][C] = (C<W[0]) ? m[1][C] : max(m[1][C], m[1][C-W[0]]+V[0]);
}

void Traceback(int n, int *W, int **m, int C, int *X){
    for(int i=0; i<n-1; i++){
        if(m[i][C]==m[i+1][C])
            X[i] = 0;
        else{
            X[i] = 1;
            C -= W[i];
        }
    }
    X[n - 1] = (m[n - 1][C] > 0) ? 1 : 0;
}

int main() {
    int n = 5; // 物品数量
    int W[] = {1, 5, 4, 2, 2}; // 物品重量
    int V[] = {4, 6, 4, 3, 2}; // 物品价值
    //int W[] = {2, 2, 6, 5, 4}; // 物品重量
    //int V[] = {6, 3, 5, 4, 6}; // 物品价值
    int C = 10; // 背包容量

    // 动态规划表
    int **m = new int*[n];
    for(int i = 0; i < n; i++) {
        m[i] = new int[C+1];
    }

    // 选择的物品
    int *X = new int[n];

    // 计算最优解
    Knapsack(n, W, V, C, m);

    // 回溯找到选择的物品
    Traceback(n, W, m, C, X);

    // 输出结果
    cout << "最大价值: " << m[0][C] << endl;
    cout << "选择的物品: ";
    for(int i = 0; i < n; i++) {
        cout << X[i] << " ";
    }
    cout << endl;

    // 释放动态分配的内存
    for(int i = 0; i < n; i++) {
        delete[] m[i];
    }
    delete[] m;
    delete[] X;

    return 0;
}
