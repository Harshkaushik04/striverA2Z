#include<bits/stdc++.h>
using namespace std;
//first convert to sum problem then solve
int countPartitions(vector<int>& arr, int d) {
    // Code here
    int n=arr.size();
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }
    if((totalSum-d)%2==1) return 0;
    if(d>totalSum) return 0;
    vector<int> current(totalSum+1,0);
    vector<int> last(totalSum+1,0);
    last[0]++;
    if(totalSum>=arr[0]) last[arr[0]]++;
    int take,not_take;
    for(int i=1;i<n;i++){
        for(int target=0;target<=totalSum;target++){
            not_take=last[target];
            take=0;
            if(target>=arr[i]) take=last[target-arr[i]];
            current[target]=(take+not_take);
        }
        last=current;
    }
    return last[(totalSum-d)/2];
}