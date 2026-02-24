#include<bits/stdc++.h>
using namespace std;

int largest(vector<int> arr){
    int max=INT32_MIN;
    int arr_size=arr.size();
    for(int i=0;i<arr_size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int getSecondLargest(vector<int> arr) {
    int max=largest(arr);
    int secondLargest=INT32_MIN;
    int arr_size=arr.size();
    for(int i=0;i<arr_size;i++){
        if(secondLargest<arr[i] && arr[i]!=max){
            secondLargest=arr[i];
        }
    }
    if(secondLargest==INT32_MIN){
        return -1;
    }
    return secondLargest;
}

int main(){
    int secondLargest=getSecondLargest({10,10,10});
    cout<<secondLargest<<endl;
    return 0;
}