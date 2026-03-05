#include<bits/stdc++.h>
using namespace std;
int find_optimal(int i,vector<int>& p_zeros){
    int n=p_zeros.size();
    if(n==0) return -1;
    if(i>=n) return -1;
    if(i==n-1) return 0;
    for(int j=i;j<n;j++){
        if(p_zeros[j]>=n-i-1){
            return j;
        }
    }
    return -1;
}

pair<bool,vector<int>> checkIfWorks(vector<vector<int>>& grid){
    unordered_map<int,int> mpp;
    int n=grid.size();
    vector<int> p_zeros(n,0);
    for(int i=0;i<n;i++){
        int p=0;
        int flag=true;
        for(int j=n-1;j>=0;j--){
            if(grid[i][j]==0) p++;
            else{
                if(mpp.find(p)!=mpp.end()) mpp[p]++;
                else mpp[p]=1;
                p_zeros[i]=p;
                flag=false;
                break;
            }
        }
        if(flag){
            if(mpp.find(p)!=mpp.end()) mpp[p]++;
            else mpp[p]=1;
            p_zeros[i]=p;
        }
    }
    int decider=n-1;
    for(int i=n;i>=0;i--){
        if(decider>i) return pair<bool,vector<int>>{false,p_zeros};
        if(decider<=0) return pair<bool,vector<int>> {true,p_zeros};
        if(mpp.find(i)!=mpp.end()) decider-=mpp[i];
    }
    return pair<bool,vector<int>> {true,p_zeros};
}

int minSwaps(vector<vector<int>>& grid) {
    pair<bool,vector<int>> check=checkIfWorks(grid);
    int n=grid.size();
    if(!check.first) return -1;
    else{
        vector<int> p_zeros=check.second;
        int ans=0;
        for(int i=0;i<n-1;i++){
            int found=find_optimal(i,p_zeros);
            if(found==-1) return -1;
            int actual_value_found=p_zeros[found];
            p_zeros.erase(p_zeros.begin()+found);
            p_zeros.insert(p_zeros.begin()+i,actual_value_found);
            ans+=abs(found-i);
        }
        return ans;
    }
}
int main(){
    return 0;
}