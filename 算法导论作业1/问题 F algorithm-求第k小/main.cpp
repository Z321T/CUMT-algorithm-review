#include <iostream>
#include <vector>
#include <algorithm>

// Declare the partition function before quickselect
int partition(std::vector<int>& arr, int left, int right, int pivotIndex);

int quickselect(std::vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotIndex = left + (right - left) / 2;
    pivotIndex = partition(arr, left, right, pivotIndex);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickselect(arr, left, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, right, k);
    }
}

int partition(std::vector<int>& arr, int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;

    for (int i = left; i < right; ++i) {
        if (arr[i] < pivotValue) {
            std::swap(arr[i], arr[storeIndex]);
            ++storeIndex;
        }
    }
    std::swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int result = quickselect(arr, 0, n - 1, k - 1);
    std::cout << result << std::endl;

    return 0;
}