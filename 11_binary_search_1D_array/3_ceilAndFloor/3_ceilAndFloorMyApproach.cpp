#include<iostream>
#include<vector>

using namespace std;

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    vector<int> result;
    int arrSize=arr.size();
    //floor
    int maxi=INT32_MIN;
    for(int i=0;i<arrSize;i++){
        if(arr[i]==x){
            maxi=x;
            break;
        }
        else if(arr[i]>maxi && arr[i]<x){
            maxi=arr[i];
        }
    }
    if(maxi==INT32_MIN){
        maxi=-1;
    }
    //ceiling
    int mini=INT32_MAX;
    for(int i=0;i<arrSize;i++){
        if(arr[i]==x){
            mini=x;
            break;
        }
        else if(arr[i]<mini && arr[i]>x){
            mini=arr[i];
        }
    }
    if(mini==INT32_MAX){
        mini=-1;
    }
    return {maxi,mini};
}