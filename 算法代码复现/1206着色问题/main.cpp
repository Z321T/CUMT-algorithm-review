#include <iostream>
using namespace std;

class Color{
public:
    int n;
    int m;
    int sum;
    int **a;
    int *ans;

    void BT(int t){
        if(t>n){
            sum++;
            for(int i=1; i<=n; i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        else{
            for(int i=1; i<=m; i++){
                ans[t]=i;
                if(OK(t)){
                    BT(i+1);
                }
            }
        }
    }

    bool OK(int t){
        for(int i=1; i<=m; i++){
            if(a[t][i]==1 && ans[t]==ans[i])
                return false;
        }
        return true;
    }
};

int mColor(int n, int **a, int m){
    Color X;
    X.n=n;
    X.m=m;
    X.a=a;
    X.sum=0;
    int *p=new int[n+1];
    for(int i=0; i<=n; i++){
        p[i]=0;
    }
    X.ans=p;
    X.BT(1);
    delete []p;
    return X.sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
