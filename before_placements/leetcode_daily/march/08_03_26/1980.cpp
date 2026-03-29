#include<bits/stdc++.h>
using namespace std;

string findDifferentBinaryString(vector<string>& nums) {
    set<string> nums_s(nums.begin(),nums.end());
    vector<string> vec={"0","1","10","11","100","101","110","111","1000","1001","1010","1011","1100","1101","1110","1111","10000"};
    int n=nums.size();
    for(int i=0;i<n+1;i++){
        int m=vec[i].size();
        string temp="";
        for(int j=0;j<n-m;j++){
            temp+="0";
        }
        temp+=vec[i];
        if(nums_s.find(temp)==nums_s.end()) return temp;
    }        
    return "-1";
}