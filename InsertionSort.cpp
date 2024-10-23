#include<iostream>

using namespace std;

int main(){
    int arr[] = {30,45,80,15,24,21,65,70,120,35,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(auto var:arr){
        cout<<var<<" ";
    }
}