#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr,int i, int mid, int j){
    int n1 = mid-i+1;
    int n2 = j - mid;
    vector<int> l1(n1), l2(n2);

    for(int k=0;k<n1;k++){
        l1[k]=arr[i+k];
    }
    for(int k=0;k<n2;k++){
        l2[k]=arr[1+mid+k];
    }

    int k1 = 0, k2 = 0;
    int k = i;
     while(k1<n1 && k2<n2){
        if (l1[k1]<=l2[k2]){
            arr[k++]=l1[k1++];
        }
        else{
            arr[k++]=l2[k2++];
        }
    }

    while(k1<n1){
        arr[k++]=l1[k1++];
    }

    while(k2<n2){
        arr[k++]=l2[k2++];
    }
}


void mergeSort(vector<int>& arr, int i, int j){
    if (i>=j) return;
    int mid = i+((j-i)/2);
    mergeSort(arr,i,mid);
    mergeSort(arr,mid+1,j);
    merge(arr,i,mid,j) ;   
}

int main(){
    vector<int> arr = {70, 20, 40, 35, 55, 68, 42, 37, 120, 49, 18, 60};
    int i = 0, j = arr.size()-1;
    mergeSort(arr,i,j);
    cout<<"Sorted array:\n";
    for(auto var : arr){
        cout<<var<<" ";
    }
}