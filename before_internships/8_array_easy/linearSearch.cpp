#include<iostream>
#include<vector>

using namespace std;


bool linearSearch(vector<int> arr, int k) {
    int arrSize=arr.size();
    for(int i=0;i<arrSize;i++){
        if(arr[i]==k){
            return true;
        }
    }
    return false;
};