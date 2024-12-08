#include <iostream>
using namespace std;

bool Place(int k){
    for(int i=1; i<k; i++){
        if(abs(k-i)==abs(x[k]-x[i]) || x[k]==x[i])
            return false;
    }
    return true;
}

void Backtrack(int k){
    if(k>n) {
        sum++;
    }
    else{
        for(int i=1; i<=n; i++){
            x[k]=i;
            if(Place(k))
                Backtrack(k+1);
        }
    }
}

int nQueen(int n){
    Queen X;
    X.n=n;
    X.sum=0;
    int *p=new int[n+1];
    for(int i=0;i<=n;i++)
        p[i]=0;
    X.x=p;
    X.Backtrack(1);
    delete []p;
    return X.sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
