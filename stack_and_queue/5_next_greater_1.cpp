#include<bits/stdc++.h>
using namespace std;

void findNextGreater(vector<int>& great,vector<int>& nums2,int s2){
    stack<int> st;
    bool flag;
    for(int i=s2-1;i>=0;i--){
        flag=false;
        while(!st.empty()){
            if(st.top()>nums2[i]){
                great[i]=st.top();
                st.push(nums2[i]);
                flag=true;
                break;
            }
            else{
                st.pop();
            }
        }
        if(!flag){
            great[i]=-1;
            st.push(nums2[i]);
        }
    }
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int s1=nums1.size(),s2=nums2.size();
    vector<int> great(s2,-1);
    findNextGreater(great,nums2,s2);
    vector<pair<int,int>> n1,n2;
    for(int i=0;i<s2;i++){
        n2.emplace_back(make_pair(nums2[i],great[i]));
    }
    sort(n2.begin(),n2.end());
    for(int i=0;i<s1;i++){
        n1.emplace_back(make_pair(nums1[i],i));
    }
    sort(n1.begin(),n1.end());
    int j=0;
    vector<int> ans(s1,-1);
    for(int i=0;i<s2;i++){
        if(j>=s1) break;
        if(n1[j].first==n2[i].first){
            ans[n1[j].second]=n2[i].second;
            j++;
        }
    }
    return ans;
}