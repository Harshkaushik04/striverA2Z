#include<iostream>
#include<vector>

using namespace std;

void Merge(vector<int>& arr,int low,int mid,int high){
    vector<int> mergedArr={};
    int tempLow=low;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]>=arr[right]){
            mergedArr.emplace_back(arr[right]);
            right++;
        }
        else if(arr[left]<=arr[right]){
            mergedArr.emplace_back(arr[left]);
            left++;
        }
    }
    while(left<=mid){
        mergedArr.emplace_back(arr[left]);
        left++;
    }
    while(right<=high){
        mergedArr.emplace_back(arr[right]);
        right++;
    }
    for(auto element:mergedArr){
        arr[tempLow]=element;
        tempLow++;
    }
}

void mergeSort(vector<int>& arr,int low,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}

int main(){
    vector<int> arr={43,21,42,3,55};
    mergeSort(arr,0,arr.size()-1);
    for(auto element:arr){
        cout<<element<<endl;
    }
    return 0;
}