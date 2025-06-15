#include<bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int sum) {
    sum=abs(sum);
    int n=nums.size();
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }
    vector<int> last(2*totalSum+1,0);
    vector<int> current(2*totalSum+1,0);
    last[totalSum+nums[0]]++;
    last[totalSum-nums[0]]++;
    int plus_take,minus_take;
    for(int i=1;i<n;i++){
        for(int target=0;target<=2*totalSum;target++){
            plus_take=0,minus_take=0;
            if(target-nums[i]>=0) plus_take=last[target-nums[i]];
            if(target+nums[i]<=2*totalSum) minus_take=last[target+nums[i]];
            current[target]=plus_take+minus_take;
        }
        last=current;
    }
    return last[sum+totalSum];
}