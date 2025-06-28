#include<bits/stdc++.h>
using namespace std;

int findUp(vector<int>& parent,vector<int>& size_arr,int u){
    if(u==parent[u]) return u;
    int up=findUp(parent,size_arr,parent[u]);
    parent[u]=up;
    return up;
}

int removeStones(vector<vector<int>>& stones) {
    int n=stones.size();
    // unordered_map<int,pair<int,int>> mpp;
    // for(int i=0;i<n;i++){
    //     mpp[i]=make_pair(stones[i][0],stones[i][1]);
    // }
    vector<int> parents;
    for(int i=0;i<n;i++){
        parents.emplace_back(i);
    }
    vector<int> size_arr(n,1);
    unordered_map<int,int> mpp_x,mpp_y;
    for(int i=0;i<n;i++){
        unordered_map<int,int>::iterator temp1=mpp_x.find(stones[i][0]);
        unordered_map<int,int>::iterator temp2=mpp_y.find(stones[i][1]);
        if(temp1!=mpp_x.end() && temp2==mpp_y.end()){
            mpp_y[stones[i][1]]=i;
            int up1=findUp(parents,size_arr,i);
            int up2=findUp(parents,size_arr,mpp_x[stones[i][0]]);
            if(up1==up2) continue;
            if(size_arr[up1]>=size_arr[up2]){
                parents[up2]=up1;
                size_arr[up1]+=size_arr[up2];
            }
            else if(size_arr[up1]<size_arr[up2]){
                parents[up1]=up2;
                size_arr[up2]+=size_arr[up1];
            }
        }
        else if(temp2!=mpp_y.end() && temp1==mpp_x.end()){
            mpp_x[stones[i][0]]=i;
            int up1=findUp(parents,size_arr,i);
            int up2=findUp(parents,size_arr,mpp_y[stones[i][1]]);
            if(up1==up2) continue;
            if(size_arr[up1]>=size_arr[up2]){
                parents[up2]=up1;
                size_arr[up1]+=size_arr[up2];
            }
            else if(size_arr[up1]<size_arr[up2]){
                parents[up1]=up2;
                size_arr[up2]+=size_arr[up1];
            }
        }
        else if(temp1==mpp_x.end() && temp2==mpp_y.end()){
            mpp_x[stones[i][0]]=i;
            mpp_y[stones[i][1]]=i;
        }
        else{ //temp1!=mpp_x.end() && temp2!=mpp_y.end()
            int up1=findUp(parents,size_arr,i);
            int up2=findUp(parents,size_arr,mpp_y[stones[i][1]]);
            if(up1==up2) continue;
            if(size_arr[up1]>=size_arr[up2]){
                parents[up2]=up1;
                size_arr[up1]+=size_arr[up2];
            }
            else if(size_arr[up1]<size_arr[up2]){
                parents[up1]=up2;
                size_arr[up2]+=size_arr[up1];
            }
            up1=findUp(parents,size_arr,i);
            up2=findUp(parents,size_arr,mpp_x[stones[i][0]]);
            if(up1==up2) continue;
            if(size_arr[up1]>=size_arr[up2]){
                parents[up2]=up1;
                size_arr[up1]+=size_arr[up2];
            }
            else if(size_arr[up1]<size_arr[up2]){
                parents[up1]=up2;
                size_arr[up2]+=size_arr[up1];
            }
        }
    }
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(findUp(parents,size_arr,i));
    }
    return n-s.size();
}