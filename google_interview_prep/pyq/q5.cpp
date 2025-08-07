#include<bits/stdc++.h>
using namespace std;
/*
Follow up - Find the kth largest odd element.
*/
/*
approach1: sort nums and then do O(n) traversal through array and keep a counter through which you calculate number of odd numbers
approach2: make a priority queue: min heap
by keaping lowest element at the top
if number of elements in pq is less than k then keep pushing into pq
else if element is lower than pq.top() then domnt push it into pq
     if element is higher than pq.top() then pop top of pq and push that element into pq
*/

int findKthLargest(vector<int>& nums, int k){
    int n=nums.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        if(nums[i]%2==1){
            if(pq.size()<k) pq.push(nums[i]);
            else{
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                } 
            }
        }
    }
    if(pq.size()<k) return -1;
    return pq.top();
}