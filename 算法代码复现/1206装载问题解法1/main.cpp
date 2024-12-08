#include <iostream>
using namespace std;

int Max(int n, int *W, int c){
    Loading<Type> X;
    X.W=W;
    X.c=c;
    X.n=n;
    X.cw=0;
    X.bestw=0;
    X.Backtrack(1);

    return X.bestw;
}

void Loading<Type>:: Backtrack(int i){
    if(i>n){
        if(cw>bestw)
            bestw=cw;
        return;
    }
    if(cw+w[i]<=c){
        cw+=w[i];
        Backtrack(i+1);
        cw-=w[i];
    }
    Backtrack(i+1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}