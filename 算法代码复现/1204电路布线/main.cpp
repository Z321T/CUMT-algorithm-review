#include <iostream>
using namespace std;

void MNS(int n, int *C, int **S){
    for(int i=1; i<=C[1]; i++){
        S[1][i] = 0;
    }
    for(int i=C[1]; i<=n; i++){
        S[1][i] = 1;
    }
    for(int i=2; i<n; i++){
        for(int j=1; j<=C[i]; j++)
            S[i][j] = S[i-1][j];
        for(int j=C[i]; j<=n; j++)
            S[i][j] = max(S[i-1][j], S[i-1][j-C[i]]+1);
    }
    S[n][n] = max(S[n-1][n], S[n-1][n-C[n]]+1);
}

int main() {

    return 0;
}
