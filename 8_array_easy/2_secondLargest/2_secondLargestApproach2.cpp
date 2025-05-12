#include<iostream>
#include<vector>

using namespace std;

int getSecondLargest(vector<int> arr) {
    int largest=arr[0];
    int secondLargest=INT32_MIN;
    int arr_size=arr.size();
    for(int i=0;i<arr_size;i++){
        if(arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>=secondLargest){
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