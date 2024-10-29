#include<bits/stdc++.h>

using namespace std;

int table[8];

int fib(int n){
    if(n<=0||n==1)
        return n;
    if (table[n-1]==-1)
        table[n-1]=fib(n-1);
    if (table[n-2]==-1)
        table[n-2]=fib(n-2);
    table[n]=table[n-1]+table[n-2];
    return table[n];
}

int main(){
    for (int k=0;k<8;k++){
        table[k]=-1;
    }
    int sum = fib(8);
    cout<<sum<<endl;
}