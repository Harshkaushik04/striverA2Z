#include<bits/stdc++.h>
using namespace std;
 int splitArray(vector<int>& nums, int k) {
    int l=INT32_MAX,h=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        l=min(l,nums[i]);
        h+=nums[i];
    }
    int mid=(l+h)/2;
    int ans=INT32_MAX;
    while(l<=h){
        int i=0;
        int sum=0;
        bool flag=true;
        int num_partitions=0;
        while(i<n && num_partitions<k){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
                i++;
            }
            else{
                num_partitions++;
                sum=0;
            }
        }
        if(i==n && num_partitions==k-1){
            ans=min(ans,mid);
            h=mid-1;
            mid=(l+h)/2;
        }
        else if(num_partitions==k){
            l=mid+1;
            mid=(l+h)/2;
        }
        else{
            ans=min(ans,mid);
            h=mid-1;
            mid=(l+h)/2;
        }
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,-1);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<splitArray(arr,k)<<endl;
    return 0;
}