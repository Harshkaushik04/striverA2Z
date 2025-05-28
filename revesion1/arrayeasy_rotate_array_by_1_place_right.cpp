#include<bits/stdc++.h>
using namespace std;
//method1
// void rotate(vector<int> nums) { //right rotation
//     int numsSize=nums.size();
//     int temp,temp1;
//     temp1=nums[0];
//     for(int i=0;i<numsSize;i++){
//         if(i!=numsSize){
//             temp=nums[i+1];
//             nums[i+1]=temp1;
//         }
//         else{
//             nums[0]=temp1;
//         }
//         temp1=temp;
//     }
// }
//method2
void rotate(vector<int> nums) { //right rotation
    int numsSize=nums.size();
    int temp;
    temp=nums[numsSize-1];
    for(int i=0;i<numsSize;i++){
        if(i!=numsSize){
            temp=nums[i+1];
            nums[i+1]=temp1;
        }
        else{
            nums[0]=temp1;
        }
        temp1=temp;
    }
}