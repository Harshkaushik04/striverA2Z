#include<bits/stdc++.h>
using namespace std;
int upper_bound(vector<int>& arr,int limit){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    int ans=-1;
    while(low<=high){
        if(arr[mid]>limit){
            high=mid-1;
            mid=(low+high)/2;
        }
        else{
            low=mid+1;
            ans=mid;
            mid=(low+high)/2;
        }
    }
    return ans;
}

int lower_bound(vector<int>& arr,int limit){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    int ans=-1;
    while(low<=high){
        if(arr[mid]>=limit){
            high=mid-1;
            ans=mid;
            mid=(low+high)/2;
        }
        else{
            low=mid+1;
            mid=(low+high)/2;
        }
    }
    return ans;
}

int nil(int lower_limit,int upper_limit,vector<int>& arr){//num_in_limits
    if (lower_limit > upper_limit) return 0;
    int n=arr.size();
    if(lower_limit>arr[n-1]) return 0;
    if(upper_limit<arr[0]) return 0;
    int lower_bound_num=lower_bound(arr,lower_limit);
    int higher_bound_num=upper_bound(arr,upper_limit);
    return higher_bound_num-lower_bound_num+1;
}

int f(int i,int whether_right_chosen,vector<pair<int,int>>& rp,vector<int>& walls,vector<vector<int>>& dp,int n){
    if(dp[i][whether_right_chosen]!=-1) return dp[i][whether_right_chosen];
    if(i==n-1){
        int right_one=nil(rp[i].first,rp[i].first+rp[i].second,walls);
        int left_one;
        int left_limit=max(rp[i-1].first+1,rp[i].first-rp[i].second);
        if(whether_right_chosen){
            int right_limit_prev=min(rp[i].first-1,rp[i-1].first+rp[i-1].second);
            int in_between=nil(left_limit,right_limit_prev,walls);
            left_one=nil(left_limit,rp[i].first,walls)-in_between;
        }
        else left_one=nil(left_limit,rp[i].first,walls);
        dp[i][whether_right_chosen]=max(right_one,left_one);
        return dp[i][whether_right_chosen];
    }
    if(i==0){
        int left_one=nil(rp[i].first-rp[i].second,rp[i].first,walls)+f(i+1,false,rp,walls,dp,n);
        int right_limit=min(rp[i].first+rp[i].second,rp[i+1].first-1);
        int right_one=nil(rp[i].first,right_limit,walls)+f(i+1,true,rp,walls,dp,n);
        dp[i][whether_right_chosen]=max(right_one,left_one);
    }
    else{
        int left_limit=max(rp[i].first-rp[i].second,rp[i-1].first+1);
        int right_limit=min(rp[i].first+rp[i].second,rp[i+1].first-1);
        int right_limit_prev=min(rp[i-1].first+rp[i-1].second,rp[i].first-1);
        int right_one=nil(rp[i].first,right_limit,walls)+f(i+1,true,rp,walls,dp,n);
        if(whether_right_chosen==0){
            int left_one=nil(left_limit,rp[i].first,walls)+f(i+1,false,rp,walls,dp,n);
            dp[i][whether_right_chosen]=max(right_one,left_one);
        }
        else{
            int in_between=nil(left_limit,right_limit_prev,walls);
            int left_one=nil(left_limit,rp[i].first,walls)-in_between+f(i+1,false,rp,walls,dp,n);
            dp[i][whether_right_chosen]=max(left_one,right_one);
        }
    }
    return dp[i][whether_right_chosen];
}

int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
    int n=robots.size();
    sort(walls.begin(),walls.end());
    if(n==1){
        int left_one=nil(robots[0]-distance[0],robots[0],walls);
        int right_one=nil(robots[0],robots[0]+distance[0],walls);
        return max(left_one,right_one);
    }
    vector<pair<int,int>> rp;
    for(int i=0;i<n;i++){
        rp.emplace_back(pair<int,int>{robots[i],distance[i]});
    }
    sort(rp.begin(),rp.end());
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,false,rp,walls,dp,n);
}


int main(){
    return 0;
}