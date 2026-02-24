#include<bits/stdc++.h>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    int n=nums.size();
    vector<int> psee(n,-1);
    vector<int> nse(n,n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
        if(!st.empty()) psee[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        if(!st.empty()) nse[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    vector<int> pgee(n,-1);
    vector<int> nge(n,n);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
        if(!st.empty()) pgee[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
        if(!st.empty()) nge[i]=st.top();
        st.push(i);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=(long long)(i-pgee[i])*(nge[i]-i)*nums[i];
        ans-=(long long)(i-psee[i])*(nse[i]-i)*nums[i];
    }
    return ans;
}

