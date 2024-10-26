#include<iostream>

using namespace std;

int max(int a, int b) { 
    return (a > b) ? a : b; 
} 
  
// A utility function to find maximum of three integers 
int max(int a, int b, int c) { 
    return max(max(a, b), c); 
} 

int maxCrossingSum(int arr[],int l, int m, int h){
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i=m;i>=l;i--){
        sum += arr[i];
        if(left_sum < sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i=m+1;i<=h;i++){
        sum += arr[i];
        if(right_sum < sum)
            right_sum = sum;
    }
    return (left_sum + right_sum) ;
}

int maxSubArraySum(int arr[],int l, int h){
    if (l > h) 
        return INT_MIN; 
    if (l==h)
        return arr[l];
    int m = (l+h)/2;
    return max(maxSubArraySum(arr, l, m - 1), 
               maxSubArraySum(arr, m + 1, h), 
               maxCrossingSum(arr, l, m, h)); 
}

int main(){
    int arr[] = {-2, 3, 4, -5, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int max_sum = maxSubArraySum(arr, 0, n - 1); 
    cout << "Maximum contiguous sum is " << max_sum; 
}