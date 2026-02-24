#include<iostream>
#include<vector>

using namespace std;

//Approach not working right now

long long sum(vector<int> arr,int i,int j){
    long long result=0;
    for(int k=i;k<=j;k++){
        result+=arr[k];
    }
    return result;
}

bool check(vector<pair<pair<int,int>,long long>> tempSums,int start,int end){
    for(auto element:tempSums){
        if(element.first.first==start || element.first.second==end){
            return false;
        }
    }
    return true;
}
int lenOfLongestSubarr(vector<int>& arr, int k) {
    int arrSize=arr.size();
    int tempSize=0;
    long long tempSum=sum(arr,0,arrSize-1);
    int tempLeft=0,tempRight=arrSize-1;
    vector<pair<pair<int,int>,long long>> sums;
    vector<pair<pair<int,int>,long long>> tempSums;
    pair<int,int> temp={0,arrSize-1};   
    sums.emplace_back(temp,tempSum);
    //starting index,end index, sum
    if(tempSum==k){
        return arrSize;
    }
    int tempArrSize=arrSize;
    //last index represents the sum of removed indexes
    for(int i=0;i<arrSize-1;i++){
        tempSums=vector<pair<pair<int,int>,long long>>();
        tempArrSize--;
        tempSize=sums.size();
        for(int j=0;j<tempSize;j++){
            tempLeft=sums[i].first.first;
            tempRight=sums[i].first.second;
            tempSum=sums[i].second;
            cout<<tempSum<<endl;
            //first
            tempLeft++;
            if(tempLeft<=tempRight){
                if(tempSum-arr[tempLeft]==k){
                    return tempArrSize;
                }
                if(check(tempSums,tempLeft,tempRight)){
                    tempSums.emplace_back(make_pair(make_pair(tempLeft,tempRight),tempSum-arr[tempLeft]));
                }
            }
            else{
                continue;
            }
            //second
            tempLeft--;
            tempRight--;
            if(tempLeft<=tempRight){
                if(tempSum-arr[tempRight]==k){
                    return tempArrSize;
                }
                if(check(tempSums,tempLeft,tempRight)){
                    tempSums.emplace_back(make_pair(make_pair(tempLeft,tempRight),tempSum-arr[tempRight]));
                }
            }
            tempRight++;
        }
        sums=tempSums;
    }
    return -1;
}

int main(){
    vector<int> arr={-59 ,-25, 58 ,-59, -25, 58};
    vector<int>& arrAdd=arr;
    int k=-85;
    int len=lenOfLongestSubarr(arrAdd,k);
    cout<<"len:"<<len<<endl;
    return 0;
}