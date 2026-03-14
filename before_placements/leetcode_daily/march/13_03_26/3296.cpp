#include<bits/stdc++.h>
using namespace std;

bool checkIfWorks(int height,vector<int>& w,long long time){
    int n=w.size();
    long long num_blocks = 0;
    for(int i=0;i<n;i++){
        double alpha=-2*time/w[i];
        double beta=-4*alpha+1;
        if(beta>=0 && (sqrt(beta)-1)/2>=0){
            num_blocks+=(long long)((sqrt(beta)-1)/2);
            if(num_blocks>=height) return true;
        }
    }
    return false;
}


long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    long long l=1,r=1e16;
    long long mid=(l+r)/2;
    long long ans=mid;
    while(l<=r){
        bool check=checkIfWorks(mountainHeight,workerTimes,mid);
        if(check){
            r=mid-1;
            ans=mid;
            mid=(l+r)/2;
        }
        else{
            l=mid+1;
            mid=(l+r)/2;
        }
        if(l>r) return ans;
    }
    return ans;
}




//pq doesnt work
// long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
//     int n=workerTimes.size();
//     priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
//     vector<int> values(n,0);
//     vector<long long> answers(n,0);
//     for(int i=0;i<n;i++) pq.push(pair<int,int>{workerTimes[i],i});
//     int counter=0;
//     while(counter<mountainHeight){
//         pair<long long,int> top_element=pq.top();
//         pq.pop();
//         answers[top_element.second]+=top_element.first;
//         values[top_element.second]++;
//         pq.push(pair<long long,int>{(long long)(values[top_element.second]+1)*workerTimes[top_element.second],top_element.second});
//         counter++;
//     }      
//     long long ans=LONG_LONG_MIN;
//     for(int i=0;i<n;i++) ans=max(ans,answers[i]);
//     return ans;
// }