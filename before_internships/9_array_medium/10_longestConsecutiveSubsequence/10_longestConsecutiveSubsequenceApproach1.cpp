#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int longestConsecutive(vector<int>& arr){
    int arrSize=arr.size();
    int maxCount=0;
    int temp=0;
    if(arrSize==0){
        return 0;
    }
    sort(arr.begin(),arr.end());
    maxCount=1;
    temp=1;
    for(int i=0;i<arrSize-1;i++){
        if(arr[i]==arr[i+1]){
            continue;
        }
        else if(arr[i]+1==arr[i+1]){
            temp++;
        }
        else{
            maxCount=max(maxCount,temp);
            temp=1;
        }
    }
    maxCount=max(maxCount,temp);
    return maxCount;
}

int main(){
    vector<int> arr={0,3,7,2,5,8,4,6,0,1};
    vector<int>& _arr=arr;
    int maxi=longestConsecutive(_arr);
    cout<<maxi<<endl;
    return 0;
}
