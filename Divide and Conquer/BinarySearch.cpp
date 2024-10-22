#include<iostream>

using namespace std;

int binarySearch(int arr[],int i,int j,int x){
    if (j>=i){
        int mid = (i+j)/2;
        if (arr[mid]==x){
            return mid;    
        }
        else if(arr[mid]>x){
            return binarySearch(arr, i,mid-1,x);
        }
        else
            return binarySearch(arr,mid+1,j,x);
    }
    return -1;
}

int main(){
    int arr[]={18,20,35,37,40,42,49,55,60,68,70,120};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = binarySearch(arr,0,n-1,55);
    if (index == -1)
        cout<<"Element not found";
    else
        cout<<index;
    return 0;
}