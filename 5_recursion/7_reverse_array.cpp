#include<iostream>
#include<vector>

using namespace std;

void reverseArray(int i,int n,vector<int> &arr) {
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    reverseArray(i+1,n,arr);
}

//itterative approach

// void reverseArray(vector<int> &arr) {
//     int arr_size=arr.size();
//     for(int j=0;j<arr_size/2;j++){
//         swap(arr[j],arr[arr_size-j-1]);
//     }
// }

int main(){
    vector<int> arr={1,4,2,5,9,10};
    int arr_size=arr.size();
    reverseArray(0,arr_size,arr);
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}