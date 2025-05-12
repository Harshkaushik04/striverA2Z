#include<iostream>
#include<vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int numsSize=nums.size();
    int maximum=0,temp=0;
    int index=0;
    while(index<numsSize){
        while(nums[index]==1){
            temp++;
            if(index<numsSize-1){
                index++;
            }
            else if(index==numsSize-1){
                break;
            }
            cout<<"hi"<<endl;
        }
        if(temp>maximum){
            maximum=temp;
        }
        while(nums[index]==0 && index<numsSize-1){
            index++;
        }
        if(index==numsSize-1){
            if(nums[index]==1){
                temp=1;
                if(maximum<temp){
                    maximum=temp;
                }
                break;
            }
            else{
                break;
            }
        }
        temp=0;
    }
    return maximum;
}

int main(){
    vector<int> nums={1,1,0,1,1,1};
    cout<<findMaxConsecutiveOnes(nums);
    return 0;
}