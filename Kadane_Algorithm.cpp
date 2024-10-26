#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(vector<int>& arr, int n){
    int sum = 0, max = 0;
    for (int i=0;i<n;i++)
    {
        sum += arr[i];
        if (sum>max) max = sum;
        if(sum<0) sum = 0;
        
    }
    return max;

}

int main(){
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
}

