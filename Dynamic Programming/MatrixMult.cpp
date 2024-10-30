#include<bits/stdc++.h>

using namespace std;
int table[3][3];

int minMult(vector<int> arr, int l, int h){
    if(l == h)
        return 0;
    else{
        int min = INT_MAX;
        for(int k=l;k<h;k++){
            if (table[l][k]==-1)
                table[l][k]=minMult(arr,l,k);
            if (table[k+1][h]==-1)
                table[k+1][h]=minMult(arr,k+1,h);
            int tmp = table[l][k]+table[k+1][h]+(arr[l-1]*arr[k]*arr[h]);
            if(min>tmp){
                min = tmp;
            }
        }
        return min;
    }
}

int main(){
    vector<int> arr = {2, 1, 3, 4, 3};
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            table[i][j]=-1;
        }
    }
    cout<<minMult(arr,1,arr.size()-1);
}