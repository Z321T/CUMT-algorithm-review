#include <iostream>
using namespace std;

int length(int x){
    int count=0;
    while(x>0){
        x=x/2;
        count++;
    }
    return count;
}

//n表示数据的个数，p表示数据，s表示最小压缩值，l表示分段的位置，b表示保存每个数据的长度
void Compress(int n, int p[], int s[], int l[], int b[]){
    int Lmax=256;
    int header=11;
    s[0]=0;
    for(int i=1; i<=n; i++){
        b[i]=length(p[i]);
        int bmax=b[i];
        s[i]=s[i-1]+bmax;
        l[i]=1;
        for(int j=2; j<=i && j<=Lmax; j++){
            if(bmax<b[i-j+1]){
                bmax=b[i-j+1];
            }
            if(s[i]>s[i-j]+j*bmax){
                s[i]=s[i-j]+j*bmax;
                l[i]=j;
            }
            s[i]+=header;
        }
    }
}

void Traceback(int n, int& i, int s[],int l[]){
    if (n == 0)
        return;
    Traceback(n-l[n],i,s,l);
    s[i++] =n-l[n];
}

void output(int s[], int l[],int b[],int n){
    cout<<"The optimal value is"<<s[n]<<endl;
    int m = 0;
    Traceback(n,m,s,l);
    s[m] = n;
    cout<<"Decompose into "<<m<<" segments "<<endl;
    for (int j=1; j <= m; j++){
        l[j] = l[s[j]];
        b[j]= b[s[j]];
    }
    for (int j=1; j<=m;j++) cout<<l[j]<<' '<<b[j]<<endl;
}

int main() {
    int n = 7;
    int p[] = {4, 6, 5, 7, 129, 138, 1};
    int s[n+1], l[n+1], b[n+1];

    Compress(n, p, s, l, b);
    output(s, l, b, n);

    return 0;
}
