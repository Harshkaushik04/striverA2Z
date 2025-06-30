#include<bits/stdc++.h>
using namespace std;

//this question is smaller version of next question, but its not solved using unordered_map, but a different method
int totalFruit(vector<int>& nums) {
    int n=nums.size();
    int l=0,r=0;
    int maxlen=0,len=0;
    int temp1=-1,temp2=-1;
    for(int i=0;i<n;i++){
        r=i;
        if(temp1==-1) {
            temp1=nums[r];
            len++;
            maxlen=max(maxlen,len);
            continue;
        }
        if(temp2==-1){
            temp2=nums[r];
            len++;
            maxlen=max(maxlen,len);
            continue;
        }
        if(nums[r]==temp1||nums[r]==temp2) len++;
        else{
            if(nums[r-1]==temp1){
                int j=r-1;
                while(j>=0 && nums[j]==temp1) j--;
                j++;
                l=j;
                temp2=nums[r];
            }
            else{
                int j=r-1;
                while(j>=0 && nums[j]==temp2) j--;
                j++;
                l=j;
                temp1=nums[r];
            }
        }
        maxlen=max(maxlen,len);
    }
    return maxlen;
}