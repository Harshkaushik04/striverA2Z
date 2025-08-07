#include<bits/stdc++.h>
using namespace std;

void get_all(vector<vector<int>>& ans,vector<vector<int>>& hashed_prev_indexes,int starter,vector<int>& current_arr,vector<int>& arr){
    current_arr.emplace_back(arr[starter]);
    if(hashed_prev_indexes[starter].size()==0){
        ans.emplace_back(current_arr);
        return;
    }
    for(int i:hashed_prev_indexes[starter]){
        get_all(ans,hashed_prev_indexes,i,current_arr,arr);
    }
    current_arr.pop_back();
}

vector<vector<int>> output_all_lis(vector<int> arr){
    int n=arr.size();
    vector<int> count_maxi(n,1);
    vector<vector<int>> hashed_prev_indexes(n,vector<int>());
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                if(count_maxi[j]+1>count_maxi[i]){
                    count_maxi[i]=count_maxi[j]+1;
                    hashed_prev_indexes[i].clear();
                    hashed_prev_indexes[i].emplace_back(j);
                }
                else if(count_maxi[j]+1==count_maxi[i]) hashed_prev_indexes[i].emplace_back(j);
            }
        }
    }
    vector<int> max_starters;
    int maxi=-1;
    for(int i=0;i<n;i++){
        if(count_maxi[i]>maxi){
            maxi=count_maxi[i];
            max_starters.clear();
            max_starters.emplace_back(i);
        }
    }
    vector<vector<int>> ans;
    for(int starter:max_starters){
        vector<int> current_arr;
        vector<vector<int>> current_ans;
        get_all(current_ans,hashed_prev_indexes,starter,current_arr,arr);
        for(vector<int>& arr:current_ans){
            reverse(arr.begin(),arr.end());
        }
        for(vector<int>& arr:current_ans){
            ans.emplace_back(arr);
        }
    }
    return ans;
}