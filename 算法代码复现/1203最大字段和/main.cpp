#include <iostream>
#include <vector>
using namespace std;

int MaxSum(int a[], int n){
    int sum = 0;
    int b = 0;
    for(int i=0; i<n; i++){
        if(b > 0){
            b += a[i];
        }
        else{
            b = a[i];
        }
        if(b > sum){
            sum = b;
        }
    }
    return sum;
}

int MaxSumOne(int a[], int n) {
    int maxSum = 0;
    int thisSum = 0;
    for (int i = 0; i < n; i++) {
        thisSum += a[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        }
        else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}

int maxSubArraySum(const vector<int>& arr) {
    int current_max = INT_MIN;
    int global_max = INT_MIN;

    for (int num : arr) {
        current_max = max(num, current_max + num);
        if (current_max > global_max) {
            global_max = current_max;
        }
    }

    return global_max;
}

int main() {
    int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int n = sizeof(a) / sizeof(a[0]);
    cout << MaxSum(a, n) << endl;
    cout << MaxSumOne(a, n) << endl;

    //vector<int> arr = {1, -2, 3, 10, -4, 7, 2, -5};
    //cout << maxSubArraySum(arr) << endl;

    return 0;
}
