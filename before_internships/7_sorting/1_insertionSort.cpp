#include<iostream>
#include<vector>

using namespace std;

vector<int> insetionSort(vector<int> arr){
    int arr_size=arr.size();
    for(int i=0;i<arr_size;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
            else{
                break;
            }
        }
    }
    return arr;
}

int main(){
    vector<int> arr=insetionSort({43,21,42,3,55});
    for(auto element:arr){
        cout<<element<<endl;
    }
    return 0;
}