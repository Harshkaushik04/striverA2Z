#include<iostream>
#include<vector>

using namespace std;

//taking pivot as first element
int Partition(vector<int>& arr,int low,int high){
    int i=low;
    int j=high;
    int pivot=arr[low];
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && low+1<=j){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int>& arr,int low,int high){
    if(low<high){
        int pIndex=Partition(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);
    }
}

int main(){
    vector<int> arr={43,21,42,3,55};
    quickSort(arr,0,arr.size()-1);
    for(auto element:arr){
        cout<<element<<endl;
    }
    return 0;
}