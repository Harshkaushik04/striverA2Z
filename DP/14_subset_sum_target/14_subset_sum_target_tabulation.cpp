#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>& arr, int sum) {
    // code here
    int n=arr.size();
    vector<int> current(sum+1,0);
    vector<int> last(sum+1,0);
    if(sum>=arr[0]){
        last[arr[0]]=1;
    }
    bool take,not_take;
    last[0]=1;
    current[0]=1;
    for(int i=1;i<n;i++){
        for(int target=1;target<=sum;target++){
           not_take=last[target];
           take=false;
           if(target>=arr[i]){
                take=last[target-arr[i]];
           }
           current[target]=(take||not_take);
        }
        last=current;
        if(last[sum]) return true;
    }
    return last[sum];
}