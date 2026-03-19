#include<bits/stdc++.h>
using namespace std;

void printMpp(unordered_map<int,int>& mpp,string s){
    cout<<s<<endl;
    for(const pair<int,int>& p:mpp){
        cout<<p.first<<":"<<p.second<<endl;
    }
}

void printVec(vector<int>& vec,string s){
    cout<<s<<endl;
    int n=vec.size();
    for(int i=0;i<n;i++) cout<<vec[i]<<",";
    cout<<endl;
}

void printMat(vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j!=m-1) cout<<mat[i][j]<<",";
            else cout<<mat[i][j];
        }
        cout<<endl;
    }
}

int largestSubmatrix(vector<vector<int>>& matrix) {
    printMat(matrix);
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> up(m,0);
    vector<int> down(m,0);
    // vector<int> left(n,0);
    // vector<int> right(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1){
                if(up[j]==i) up[j]++;
                // if(left[i]==j) left[i]++;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(matrix[i][j]==1){
                if(down[j]==n-i-1) down[j]++;
                // if(right[i]==m-j-1) right[i]++;
            }
        }
    }
    printVec(down,"down");
    printVec(up,"up");
    // printVec(left,"left");
    // printVec(right,"right");
    unordered_map<int,int> up_mpp,down_mpp;
    // unordered_map<int,int> left_mpp,right_mpp;
    // for(int i=0;i<n;i++){
    //     if(left_mpp.find(left[i])==left_mpp.end()) left_mpp[left[i]]=1;
    //     else left_mpp[left[i]]++;
    //     if(right_mpp.find(right[i])==right_mpp.end()) right_mpp[right[i]]=1;
    //     else right_mpp[right[i]]++;
    // }
    for(int i=0;i<m;i++){
        if(down_mpp.find(down[i])==down_mpp.end()) down_mpp[down[i]]=1;
        else down_mpp[down[i]]++;
        if(up_mpp.find(up[i])==up_mpp.end()) up_mpp[up[i]]=1;
        else up_mpp[up[i]]++;
    }
    printMpp(up_mpp,"up_mpp");
    printMpp(down_mpp,"down_mpp");
    // printMpp(left_mpp,"left_mpp");
    // printMpp(right_mpp,"right_mpp");
    int maxi_area=0;
    int up_god=0,down_god=0;
    // int left_god=0,right_god=0;
    // for(int i=n;i>0;i--){
    //     if(left_mpp.find(i)!=left_mpp.end()){
    //         left_god+=left_mpp[i];
    //         maxi_area=max(maxi_area,i*left_god);
    //     }
    //     if(right_mpp.find(i)!=right_mpp.end()){
    //         right_god+=right_mpp[i];
    //         maxi_area=max(maxi_area,i*right_god);
    //     }
    // }
    for(int i=m;i>0;i--){
        if(down_mpp.find(i)!=down_mpp.end()){
            down_god+=down_mpp[i];
            maxi_area=max(maxi_area,i*down_god);
        }
        if(up_mpp.find(i)!=up_mpp.end()){
            up_god+=up_mpp[i];
            maxi_area=max(maxi_area,i*up_god);
        }
    }
    cout<<"down_god:"<<down_god<<endl;
    cout<<"up_god:"<<up_god<<endl;
    // cout<<"left_god:"<<left_god<<endl;
    // cout<<"right_god:"<<right_god<<endl;
    return maxi_area;
}

int main(){
    vector<vector<int>> mat={{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,0,0,1,1,1,0,1,0,1,0,1,1,0},{0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,0,1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},{1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1},{1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1},{1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1},{1,1,1,0,0,1,1,0,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,0}};
    cout<<largestSubmatrix(mat)<<endl;
    return 0;
}