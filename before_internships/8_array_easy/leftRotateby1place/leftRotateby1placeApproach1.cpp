#include<iostream>
#include<vector>

using namespace std;

vector<int>& leftRotateBy1Place(vector<int>& arr){
    int temp;
    int n=arr.size();
    temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    vector<int> new_arr=leftRotateBy1Place(arr);
    int newLength=new_arr.size();
    for(int i=0;i<newLength;i++){
        cout<<new_arr[i]<<endl;
    }
    return 0;
}