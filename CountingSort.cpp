#include<iostream>
#include<vector>

using namespace std;

int main(){
    int arr[] = { 4, 3, 12, 1, 5, 5, 3, 9 };
    int max = arr[0];int length = sizeof(arr)/sizeof(arr[0]);
    for (int i = 1;i<length;i++){
        if (arr[i]>max){
            max = arr[i];
        }
    }
    vector<int> list(max+1,0), array(length,0);
    for(auto var:arr){
        list[var]++;
    }
    for (int i=1;i<max+1;i++){
        list[i]+=list[i-1];
    }
    for (int i=max+1;i>0;i--){
        list[i]=list[i-1];
    }
    list[0]=0;
    for (auto var:arr){
        int tmp = list[var];
        array[tmp]=var;
        list[var]++;
    }
    for(auto var:array){
        cout<<var<<" ";
    }
}