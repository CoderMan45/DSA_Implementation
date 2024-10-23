#include<iostream>

using namespace std;

int main(){
    int arr[] = {30,45,80,15,24,21,65,70,120,35,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
    for(int var:arr){
        cout<<var<<" ";
    }
}