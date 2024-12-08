#include <iostream>
using namespace std;

// 快速排序程序的实现
int partition(int arr[], int l, int r){
    int it = l + rand() % (r - l + 1);
    swap(arr[it], arr[l]);
    int x = arr[l];
    int i = l;
    int j = r+1;

    while(true){
        while(arr[++i] < x && i < j);
        while(arr[--j] > x);
        if(i >= j) break;
        swap(arr[i], arr[j]);
    }
    arr[l] = arr[j];
    arr[j] = x;
    return j;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int q = partition(arr, l, r);
        quickSort(arr, l, q-1);
        quickSort(arr, q+1, r);
    }
}

int main() {
    int arr[] = {8, 4, 1, 7, 11, 5, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
