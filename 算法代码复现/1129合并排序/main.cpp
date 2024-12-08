#include <iostream>
// 实现合并排序的代码
// 合并两个子数组的函数
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // 左子数组的大小
    int n2 = r - m;     // 右子数组的大小

    // 创建临时数组
    int L[n1], R[n2];

    // 拷贝数据到临时数组 L[] 和 R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // 合并临时数组回 arr[l..r]
    i = 0; // 初始索引第一个子数组
    j = 0; // 初始索引第二个子数组
    k = l; // 初始索引合并的子数组
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝 L[] 的剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 拷贝 R[] 的剩余元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l 是子数组的起始索引
// r 是子数组的结束索引
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // 找到中间点
        int m = (r - l) / 2;

        // 分别对左右子数组进行排序
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // 合并排序后的子数组
        merge(arr, l, m, r);
    }
}

// 打印数组的函数
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << "\n";
}

// 测试代码
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}