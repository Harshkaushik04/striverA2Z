#include<bits/stdc++.h>
using namespace std;
//wrong:trying to solve problem of zero
// int perfectSum(vector<int>& arr, int target) {
//     // code here
//     int n=arr.size();
//     vector<int> current(target+1,0);
//     vector<int> last(target+1,0);
//     if(arr[0]==0){
//         last[0]=2;
//     }
//     else last[0]=1;
//     if(arr[0]<=target) last[arr[0]]=1;
//     int take,not_take;
//     for(int i=1;i<n;i++){
//         for(int sum=1;sum<=target;sum++){
//             not_take=last[sum];
//             take=0;
//             if(sum>=arr[i]) take=last[sum-arr[i]];
//             current[sum]=take+not_take;
//         }
//         last=current;
//     }
//     return last[target];
// }

//right:trying to solve problem of zero
//first change array to non zeros and find number of zeros then 
//ans=<normal ans>*pow(2,num_zeros)
// int perfectSum(vector<int>& arr, int target) {
//     // code here
//     int n=arr.size();
//     vector<int> current(target+1,0);
//     vector<int> last(target+1,0);
//     vector<int> new_arr;
//     int num_zero=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]==0) num_zero++;
//         else new_arr.emplace_back(arr[i]);
//     }
//     int m=new_arr.size();
//     if(m==0) return pow(2,num_zero);
//     last[0]=1;
//     current[0]=1;
//     if(new_arr[0]<=target) last[new_arr[0]]=1;
//     int take,not_take;
//     for(int i=1;i<m;i++){
//         for(int sum=1;sum<=target;sum++){
//             not_take=last[sum];
//             take=0;
//             if(sum>=new_arr[i]) take=last[sum-new_arr[i]];
//             current[sum]=take+not_take;
//         }
//         last=current;
//     }
//     return last[target]*pow(2,num_zero);
// }


//better solution
int perfectSum(vector<int>& arr, int target) {
    // code here
    int n=arr.size();
    vector<int> last(target+1,0);
    vector<int> current(target+1,0);
    last[0]++;
    if(arr[0]<=target) last[arr[0]]++;
    int take,not_take;
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=target;sum++){
            not_take=last[sum];
            take=0;
            if(sum>=arr[i]) take=last[sum-arr[i]];
            current[sum]=take+not_take;
        }
        last=current;
    }
    return last[target];
}

