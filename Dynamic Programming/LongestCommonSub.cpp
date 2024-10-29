#include<bits/stdc++.h>

using namespace std;

int table[6][6];
char s1[] = {'B','A','B','A','B','A'};
char s2[] = {'A','B','A','B','A','A'};

int max(int a, int b){
    return (a>b?a:b);
}

int LCS(int m, int n){
    if( m<0 || n<0 )
        return 0;
    if (s1[m]==s2[n]){
        return (1+LCS(m-1,n-1));
    }
    else{
        return max(LCS(m-1,n),LCS(m,n-1));
    }
}
    

int main(){
    int m = sizeof(s1)/sizeof(s1[0]);
    int n = sizeof(s2)/sizeof(s2[0]);
    int res = LCS(m-1,n-1); 
    cout<<res<<endl;
}