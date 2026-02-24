#include<bits/stdc++.h>
using namespace std;

//using pq
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     int n=nums.size();
//     priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
//     for(int i=0;i<k;i++){
//         pq.push(make_pair(nums[i],i));
//     }
//     int i=0;
//     vector<int> ans;
//     ans.emplace_back(pq.top().first);
//     for(int j=k;j<n;j++){
//         i++;
//         pq.push(make_pair(nums[j],j));
//         while(!pq.empty() && pq.top().second<i) pq.pop();
//         ans.emplace_back(pq.top().first);
//     }
//     return ans;
// }

//deque
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    int n=nums.size();
    for(int i=0;i<k;i++){
        while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
        dq.push_back(i);
    }
    vector<int> ans;
    ans.emplace_back(nums[dq.front()]);
    for(int i=k;i<n;i++){
        if(dq.front()<i-k+1) dq.pop_front();
        while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
        dq.push_back(i);
        ans.emplace_back(nums[dq.front()]);
    }
    return ans;
}