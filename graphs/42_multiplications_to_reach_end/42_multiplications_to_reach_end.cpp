#include<bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    // code here
    //number space: 0 to 99999
    int arr_size=arr.size();
    queue<int> q;
    vector<int> visited_arr(100000,-1);
    q.push(start);
    visited_arr[start]=1;
    int ans=0;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            int current=q.front();
            q.pop();
            if(current==end) return ans;
            for(int j=0;j<arr_size;j++){
                int neighbor=(current*arr[j])%100000;
                if(visited_arr[neighbor]==-1){
                    visited_arr[neighbor]=1;
                    q.push(neighbor);
                }
            }
        }
        ans++;
    }
    return -1;
}
