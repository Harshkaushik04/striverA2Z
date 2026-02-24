#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    int n=nums.size();
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;i--){
        if(st.empty()) st.push(nums[i]);
        else{
            while(!st.empty() && st.top()<=nums[i]) st.pop();
            if(st.empty()) st.push(nums[i]);
            else st.push(nums[i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(st.empty()) st.push(nums[i]);
        else{
            while(!st.empty() && st.top()<=nums[i]) st.pop();
            if(st.empty()) st.push(nums[i]);
            else{
                ans[i]=st.top();
                st.push(nums[i]);
            }
        }
    }
    return ans;
}