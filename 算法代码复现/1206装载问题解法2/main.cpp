#include <iostream>
using namespace std;

int Maxloading(int n, int C, int *W){
    loading<Type> X;
    X.W=W;
    X.C=C;
    X.n=n;
    X.bestw=0;
    X.cw=0;
    X.rw=0; //剩余集装箱的重量和
    for(int i=0; i<n; i++){
        X.rw+=W[i];
    }
    X.BT(1);

    return X.bestw;
}

void BT(int i){
    if(i>n){
        bestw=cw;
        return;
    }
    rw-=W[i];
    if(cw+W[i]<=C){
        cw+=W[i];
        BT(i+1);
        cw-=W[i];
    }
    if(cw+rw>bestw){
        BT(i+1);
    }
    rw+=W[i];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
