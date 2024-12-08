#include<iostream>
using namespace std;

void LCS_length(char *X, char *Y, int m, int n, int **c, int **b)
{
    c[0][0] = 0;
    b[0][0] = 2;
    for (int i = 1; i <= m; i++)
        c[i][0] = 0;
    for (int j = 1; j <= n; j++)
        c[0][j] = 0;
    for (int i = 1; i<=m;i++){
        for (int j=1; j<=n; j++){
            if (X[i] == Y[j]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 1;
            }
            else if (c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }
}

void LCS(int i, int j, char *X, int **b){
    if (i==0 || j==0)
        return;
    if (b[i][j] == 1){
        LCS(i-1,j-1,X,b);
        cout << X[i];
    }
    else if (b[i][j] == 2)
        LCS(i-1,j,X,b);
    else
        LCS(i,j-1,X,b);
}

int main()
{
    char X[] = "0ABCBDAB";
    char Y[] = "0BDCABA";
    int m = 7;
    int n = 6;
    int **c = new int*[m+1];
    int **b = new int*[m+1];
    for (int i = 0; i <= m; i++){
        c[i] = new int[n+1];
        b[i] = new int[n+1];
    }
    LCS_length(X,Y,m,n,c,b);
    LCS(m,n,X,b);

    for (int i = 0; i <= m; i++) {
        delete[] c[i];
        delete[] b[i];
    }
    delete[] c;
    delete[] b;

    return 0;
}