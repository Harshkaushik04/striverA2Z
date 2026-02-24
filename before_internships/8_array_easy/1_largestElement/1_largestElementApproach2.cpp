#include<iostream>
#include <cstdint>   
#include <climits>   
#include <cinttypes> 
#include<vector>

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

int main(){
    return 0;
}