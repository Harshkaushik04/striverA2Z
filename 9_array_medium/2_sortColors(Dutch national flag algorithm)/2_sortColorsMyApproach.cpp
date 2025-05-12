#include<iostream>
#include<vector>
using namespace std;

void printArr(vector<int>& arr){
    int arrSize=arr.size();
    for(int i=0;i<arrSize;i++){
        cout<<arr[i];
        if(i!=arrSize-1){
            cout<<"->";
        }
        else{
            cout<<endl;
        }
    }
}


//Dutch national flag algorithm
void sortColors(vector<int>& nums) {
    int numsSize=nums.size();
    int low=0,mid=0,high=numsSize-1;
    while(mid<=high){
        if(nums[mid]==0 && mid<=high){
            swap(nums[low],nums[mid]);
            low++;mid++;
        }
        else if(nums[mid]==1 && mid<=high){
            mid++;
        }
        else if(nums[mid]==2 && mid<=high){
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}

int main(){
    vector<int> arr={2,0,2,1,1,0};
    sortColors(arr);
    printArr(arr);
    return 0;
}