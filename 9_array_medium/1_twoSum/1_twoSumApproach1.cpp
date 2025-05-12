#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//pair is guaranteed
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> numsCopy=nums;
    sort(numsCopy.begin(),numsCopy.end());
    int numsSize=nums.size();
    int i=0,j=numsSize-1;
    long tempSum=target-1; //initialize
    int num1,num2;
    int index1=-1,index2=-1;
    while(i<j){
        tempSum=(long)numsCopy[i]+numsCopy[j];
        if(tempSum==target){
            num1=numsCopy[i],num2=numsCopy[j];       
            break;     
        }
        else if(tempSum>target){
            j--;
        }
        else{
            i++;
        }
    }
    for(int k=0;k<numsSize;k++){
        cout<<nums[k]<<endl;
        if(nums[k]==num1 && k!=index2 && index1==-1){
            index1=k;
        }
        if(nums[k]==num2 && k!=index1 && index2==-1){
            index2=k;
        }
    }
    return {index1,index2};
}

int main(){
    vector<int> nums={3,3};
    int target=6;
    vector<int> indexes=twoSum(nums,target);
    cout<<indexes.size()<<endl;
    cout<<indexes[0]<<" "<<indexes[1]<<endl;
    return 0;
}