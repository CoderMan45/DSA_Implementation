#include<iostream>
#include<vector>
#include<utility>
#include<climits>

using namespace std;

pair<int,int> MaxMin(vector<int> arr, int l,int h){
    pair<int,int> maxmin(INT_MIN,INT_MAX);
    if (l==h){
        maxmin.first = arr[l];
        maxmin.second = arr[l];
        return maxmin;
    }
    else{
        int mid = (l+h)/2;
        pair<int,int> maxmin1(INT_MIN,INT_MAX),maxmin2(INT_MIN,INT_MAX);
        maxmin1 = MaxMin(arr, l, mid);
        maxmin2 = MaxMin(arr, mid+1, h);
        if(maxmin1.first> maxmin2.first)
            maxmin.first = maxmin1.first;
        else    
            maxmin.first = maxmin2.first;
        if(maxmin1.second < maxmin2.second)
            maxmin.second = maxmin1.second;
        else    
            maxmin.second = maxmin2.second;
        return maxmin;
    }
}

int main(){
    vector<int> arr = {9, 14 ,11 ,25 ,13, 7, 85, 10, 22, 17, 50};
    pair<int,int> maxmin(INT_MIN,INT_MAX) ;
    maxmin = MaxMin(arr, 0, arr.size()-1);
    cout<<"The maximum element is : "<<maxmin.first<<endl;
    cout<<"The minimum element is : "<<maxmin.second<<endl;

}