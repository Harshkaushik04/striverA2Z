#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    int s2=nums.size();
    vector<int> great(s2,-1);
    for(int i=s2-1;i>=0;i--) st.push(nums[i]);
    bool flag;
    for(int i=s2-1;i>=0;i--){
        flag=false;
        while(!st.empty()){
            if(st.top()>nums[i]){
                great[i]=st.top();
                st.push(nums[i]);
                flag=true;
                break;
            }
            else{
                st.pop();
            }
        }
        if(!flag){
            great[i]=-1;
            st.push(nums[i]);
        }
    }
    return great;
}