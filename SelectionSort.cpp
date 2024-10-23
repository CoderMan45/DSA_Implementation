#include<iostream>

using namespace std;

int main(){
    int arr[] = {30,45,80,15,24,21,65,70,120,35,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0;i<n-1;i++){
        int min = i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[min]){
                min = j;
            }
        }
        int tmp = arr[i];
        arr[i]=arr[min];
        arr[min]=tmp;
    }
    for (int var:arr){
        cout<<var<<" ";
    }
}