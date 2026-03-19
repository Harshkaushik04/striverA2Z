#include<bits/stdc++.h>
using namespace std;

int calculate_perimater(int i,int j,int k,vector<vector<int>>& grid){
    // cout<<"i,j,k:"<<i<<","<<j<<","<<k<<endl;
    if(i==1) return grid[j][k];
    int initial_j=j,initial_k=k;
    int ans=0;
    for(int a=0;a<i-1;a++){
        j++;
        k++;
        if(a!=i-2) ans+=grid[j][k];
    }
    for(int a=0;a<i-1;a++){
        j--;
        k++;
        if(a!=i-2) ans+=grid[j][k];
    }
    for(int a=0;a<i-1;a++){
        j--;
        k--;
        if(a!=i-2) ans+=grid[j][k];
    }
    for(int a=0;a<i-1;a++){
        j++;
        k--;
        if(a!=i-2) ans+=grid[j][k];
    }
    ans+=grid[j][k];
    ans+=grid[j+i-1][k+i-1];
    ans+=grid[j][k+2*i-2];
    ans+=grid[j-i+1][k+i-1];
    return ans;
}

// void printArr(vector<pair<int,vector<int>>>& ans){
//     int ssize=ans.size();
//     for(int i=0;i<ssize;i++){
//         pair<int,vector<int>> p=ans[i];
//         int val=p.first;
//         vector<int> arr=p.second;
//         int m=arr[0],j=arr[1],k=arr[2];
//         cout<<"val:"<<val<<","<<"i,j,k:"<<m<<","<<j<<","<<k<<endl;
//     }
// }

vector<int> getBiggestThree(vector<vector<int>>& grid) {
    priority_queue<int,vector<int>> pq;
    // priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>> modified_pq;
    int n=grid.size();
    int m=grid[0].size();
    int alpha=min(m,n);
    for(int i=1;i<=(alpha+1)/2;i++){
        for(int j=i-1;j<(n-i+1);j++){
            for(int k=0;k<(m-2*i+2);k++){
                int initial_j=j,initial_k=k;
                int ans=0;
                if(i==1){
                    ans=grid[j][k];
                    pq.push(ans);
                    continue;
                }
                for(int a=0;a<i-1;a++){
                    j++;
                    k++;
                    if(a!=i-2) ans+=grid[j][k];
                }
                for(int a=0;a<i-1;a++){
                    j--;
                    k++;
                    if(a!=i-2) ans+=grid[j][k];
                }
                for(int a=0;a<i-1;a++){
                    j--;
                    k--;
                    if(a!=i-2) ans+=grid[j][k];
                }
                for(int a=0;a<i-1;a++){
                    j++;
                    k--;
                    if(a!=i-2) ans+=grid[j][k];
                }
                ans+=grid[j][k];
                ans+=grid[j+i-1][k+i-1];
                ans+=grid[j][k+2*i-2];
                ans+=grid[j-i+1][k+i-1];
                pq.push(ans);
                // modified_pq.push(pair<int,vector<int>>{mm,vector<int>{i,j,k}});
            }
        }
    }
    // pair<int,vector<int>> another_first=modified_pq.top();
    // cout<<"val:"<<another_first.first<<",i,j,k:"<<another_first.second[0]<<","<<another_first.second[1]<<","<<another_first.second[2]<<endl;
    vector<int> ans;
    int first=pq.top();
    pq.pop();
    ans.emplace_back(first);
    if(pq.empty()) return ans;
    int second=pq.top();
    pq.pop();
    while(!pq.empty() && second==first){
        second=pq.top();
        pq.pop();
    }
    if(second!=first) ans.emplace_back(second);
    if(pq.empty()) return ans;
    int third=pq.top();
    pq.pop();
    while(!pq.empty() && third==second){
        third=pq.top();
        pq.pop();
    }
    if(third!=second) ans.emplace_back(third);
    return ans;
}
int main(){
    vector<vector<int>> grid={{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
    vector<int> ans=getBiggestThree(grid);
    int ssize=ans.size();
    for(int i=0;i<ssize;i++) cout<<ans[i]<<endl;
    return 0;
}