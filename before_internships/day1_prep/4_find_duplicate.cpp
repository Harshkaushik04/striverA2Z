#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n=nums.size();
    int slow_pointer=nums[0],fast_pointer=nums[nums[0]];
    int i=0;
    while(slow_pointer!=fast_pointer){
        slow_pointer=nums[slow_pointer];
        fast_pointer=nums[nums[fast_pointer]];
        i++;
    }
    int initial_pointer=0;
    int another_pointer=slow_pointer;
    while(initial_pointer!=another_pointer){
        initial_pointer=nums[initial_pointer];
        another_pointer=nums[another_pointer];
    }
    return initial_pointer;
}