#include<iostream>
#include<vector>

using namespace std;

vector<int> bubbleSort(vector<int> arr){
    int arr_size=arr.size();
    for(int i=0;i<arr_size;i++){
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    return arr;
}

int main(){
    vector<int> arr=bubbleSort({43,21,42,3,55});
    for(auto element:arr){
        cout<<element<<endl;
    }
    return 0;
}