#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& arr) {
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2==1) return false;
    vector<int> current(sum/2+1,0);
    vector<int> last(sum/2+1,0);
    current[0]=1,last[0]=1;
    if(sum/2>=arr[0]){
        last[arr[0]]=1;
    }
    bool take,not_take;
    for(int i=1;i<n;i++){
        for(int target=1;target<=sum/2;target++){
            not_take=last[target];
            take=false;
            if(target>=arr[i]) take=last[target-arr[i]];
            current[target]=(take||not_take);
        }
        last=current;
        if(last[sum/2]) return true;
    }
    return last[sum/2];
}