#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int>& arr){
    int arrSize=arr.size();
    unordered_set<int> mySet;
    int maxCount=0;
    int tempCount=0;
    int temp;
    if(arrSize==0){
        return 0;
    }
    maxCount=1;
    for(int i=0;i<arrSize;i++){
        mySet.insert(arr[i]);
    }
    for(int element:mySet){
        if(mySet.find(element-1)!=mySet.end()){
            continue;
        }
        else{
            temp=element+1;
            tempCount=1;
            while(mySet.find(temp)!=mySet.end()){
                temp++;
                tempCount++;
            }
            maxCount=max(maxCount,tempCount);
        }
    }
    return maxCount;
}

int main(){
    // vector<int> arr={0,3,7,2,5,8,4,6,0,1};
    // vector<int>& _arr=arr;
    // int maxi=longestConsecutive(_arr);
    // cout<<maxi<<endl;
    return 0;
}