#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string nums, int k) {
    int counter=k;
    int i=0;
    int n=nums.size();
    vector<int> nse(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        if(!st.empty()) nse[i]=st.top();
        st.push(i);
    }
    string ans;
    while(i<n && counter>0){
        if(nse[i]-i<=counter){
            counter-=(nse[i]-i);
            i+=(nse[i]-i);
        }
        else{
            ans+=nums[i];
            i++;
        }
    }
    while(i<n){
        ans+=nums[i];
        i++;
    }
    string actual_ans;
    i=0;
    int ans_size=ans.size();
    while(ans[i]=='0'){
        i++;
    }
    while(i<ans_size){
        actual_ans+=ans[i];
        i++;
    }
    if(actual_ans.size()==0) return "0";
    return actual_ans;
}