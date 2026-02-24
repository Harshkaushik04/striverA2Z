#include<iostream>
#include<vector>

using namespace std;

void selectMinOperation(vector<int>& arr,int i,int j){
    int mini=arr[i];
    int miniIndex=i;
    if(i==j){
        return;
    }
    for(int k=i+1;k<=j;k++){
        if(arr[k]<mini){
            mini=arr[k];
            miniIndex=k;
        }
    }
    swap(arr[miniIndex],arr[i]);
}

vector<int> selectionSort(vector<int> arr){
    int arr_size=arr.size();
    for(int i=0;i<arr_size;i++){
        selectMinOperation(arr,i,arr_size-1);
    }
    return arr;
}

int main(){
    vector<int> arr=selectionSort({43,21,42,3,55});
    for(auto element:arr){
        cout<<element<<endl;
    }
    return 0;
}