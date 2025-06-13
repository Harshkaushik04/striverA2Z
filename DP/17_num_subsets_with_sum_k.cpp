#include<bits/stdc++.h>
using namespace std;
//wrong
int perfectSum(vector<int>& arr, int target) {
    // code here
    int n=arr.size();
    vector<int> current(target+1,0);
    vector<int> last(target+1,0);
    current[0]=1;
    last[0]=1;
    if(arr[0]<=target) last[arr[0]]=1;
    bool take,not_take;
    for(int i=1;i<n;i++){
        for(int sum=1;sum<=target;sum++){
            not_take=last[sum];
            take=0;
            if(sum>=arr[i]) take=last[sum-arr[i]];
            current[sum]=take+not_take;
        }
        last=current;
    }
    return last[target];
}
