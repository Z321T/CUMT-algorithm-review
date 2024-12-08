#include <iostream>
using namespace std;

void GreedySelector(int n, int s[], int f[], bool A[]){
    A[0] = true;
    int j = 0;
    for(int i=1; i<n; i++){
        if(s[i]>=f[j]){
            A[i] = true;
            j = i;
        }
        else{
            A[i] = false;
        }
    }
}

int main() {
    // Test case
    int n = 11;
    int s[] = {1,3,0,5,3,5,6,8,8,2,12};
    int f[] = {4,5,6,7,8,9,10,11,12,13,14};
    bool A[n];

    GreedySelector(n, s, f, A);
    for(int i=0; i<n; i++){
        if(A[i]){
            cout << i+1 << " ";
        }
    }
    cout << endl;
    return 0;
}
