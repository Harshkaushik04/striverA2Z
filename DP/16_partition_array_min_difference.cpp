#include<bits/stdc++.h>
using namespace std;
int minDifference(vector<int>&arr)  { 
    int n=arr.size();
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }
    vector<int> current(totalSum+1,0);
    vector<int> last(totalSum+1,0);
    current[0]=1;
    last[0]=1;
    last[arr[0]]=1;
    bool take,not_take;
    for(int i=1;i<n;i++){
        for(int target=1;target<=totalSum;target++){
            not_take=last[target];
            take=false;
            if(target>arr[i]) take=last[target-arr[i]];
            current[target]=(take||not_take);
        }
        last=current;
    }
    int ans=INT32_MAX;
    int temp;
    for(int i=0;i<totalSum;i++){
        if(last[i]){
            temp=abs(totalSum-2*i);
            if(ans>temp) ans=temp;
        }
    }
    return ans;
} 
