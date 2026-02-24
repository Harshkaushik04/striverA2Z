#include<bits/stdc++.h>
using namespace std;

vector<int> int_to_digit(int a){
    vector<int> ans;
    while(a!=0){
        ans.emplace_back(a%10);
        a/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

pair<int,bool> compare_two_digits_arr(vector<int>& arr1,vector<int>& arr2){ //if arr1 was smaller=>true, if arr2 was smaller=>false
    int m=arr1.size();
    int n=arr2.size();
    int i1=0,i2=0;
    while(i1<m && i2<n){
        if(arr1[i1]==arr2[i2]){
            i1++;
            i2++;
        }
        else{
            if(arr1[i1]<arr2[i2]) return make_pair(i1,true);
            else return make_pair(i1,false);
        }
    }
    if(m<=n) return make_pair(i1,true);
    return make_pair(i1,false);
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    vector<vector<int>> nums1,nums2;
    int n1=arr1.size();
    int n2=arr2.size();
    for(int i=0;i<n1;i++) nums1.emplace_back(int_to_digit(arr1[i]));
    for(int i=0;i<n2;i++) nums2.emplace_back(int_to_digit(arr2[i]));
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int i=0,j=0;
    int maxi=0;
    while(i<n1 && j<n2){
         pair<int,bool> p=compare_two_digits_arr(nums1[i],nums2[j]);
         maxi=max(maxi,p.first);
         if(p.second) i++;
         else j++;
    }
    return maxi;
}