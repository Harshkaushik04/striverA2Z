#include<bits/stdc++.h>
using namespace std;
//not done
// int candy(vector<int>& ratings) {
//     int n=ratings.size();
//     if(n==1) return 1;
//     vector<int> lowerL,lowerR,lowerB,lowerN;
//     for(int i=0;i<n;i++){
//         if(i==0){
//             if(ratings[1]>=ratings[0]) lowerN.emplace_back(0);
//             else lowerR.emplace_back(0);
//         }
//         else if(i==n-1){
//             if(ratings[n-2]>=ratings[n-1]) lowerN.emplace_back(n-1);
//             else lowerL.emplace_back(n-1);
//         }
//         else{
//             if(ratings[i+1]>=ratings[i] && ratins[i-1]>=ratings[i]) lowerN.emplace_back()
//         }
//     }
// }