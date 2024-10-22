#include <iostream>
#include<vector>

using namespace std;

int partition(vector<int>& arr, int i, int j){
    int pivot = arr[j];
    int m=i;
    for(int n = i;n<j;n++){
        if (pivot>arr[n]){
            int tmp = arr[m];
            arr[m]=arr[n];
            arr[n]=tmp;
            m++;
        }
    }
    arr[j]=arr[m];
    arr[m]=pivot;
    return m;
}

void qsort(vector<int>& arr, int i, int j){
    if(i<j){
        int pi = partition(arr,i,j);
        qsort(arr,i,pi-1);
        qsort(arr,pi+1,j);
    }
}

int main(){
    vector<int> arr = {70, 20, 40, 35, 55, 68, 42, 37, 120, 49, 18, 60};
    int n = arr.size()-1;
    qsort(arr,0,n);
    for(auto var:arr){
        cout<<var<<" ";
    }
    return 0;
}