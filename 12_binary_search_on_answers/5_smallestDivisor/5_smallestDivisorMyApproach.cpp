#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// int findMax(vector<int> nums){
//     int maxi=nums[0];
//     for(int element:nums){
//         if(element>maxi){
//             maxi=element;
//         }
//     }
//     return maxi;
// }

int ceilDivision(int m,int n){
    if(m%n==0){
        return m/n;
    }
    else{
        return m/n+1;
    }
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int maxi=*max_element(nums.begin(),nums.end());
    int low=1,high=maxi,mid=(low+high)/2;
    int sum=0;
    int mini=mid;
    while(low<=high){
        sum=0;
        for(int element:nums){
            sum+=ceilDivision(element,mid);
            if(sum>threshold){
                break;
            }
        }   
        cout<<"mid:"<<mid<<",sum:"<<sum<<endl;
        if(sum>threshold){
            low=mid+1;
            mid=(low+high)/2;
        }
        else if(sum<=threshold){
            high=mid-1;
            mini=mid;
            mid=(low+high)/2;
        }
    }
    return mini;
}

int main(){
    vector<int> nums={200,100,14};
    int threshold=10;
    int ans=smallestDivisor(nums,threshold);
    cout<<ans<<endl;
    return 0;
}