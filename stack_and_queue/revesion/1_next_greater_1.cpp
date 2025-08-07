#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    int n1=nums1.size();
    int n2=nums2.size();
    vector<int> ans(n2,-1);
    for(int i=n2-1;i>=0;i--){
        if(st.empty()) st.push(nums2[i]);
        else{
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(st.empty()) st.push(nums2[i]);
            else{
                ans[i]=st.top();
                st.push(nums2[i]);
            }
        }
    }
    unordered_map<int,int> mpp;
    for(int i=0;i<n2;i++) mpp[nums2[i]]=i;
    vector<int> actual_ans(n1,-1);
    for(int i=0;i<n1;i++) actual_ans[i]=ans[mpp[nums1[i]]];
    return actual_ans;
}