#include<bits/stdc++.h>
using namespace std;

int findUp(vector<int>& parent,vector<int>& size_arr,int u){
    if(u==parent[u]) return u;
    int up=findUp(parent,size_arr,parent[u]);
    parent[u]=up;
    return up;
}

//method3(most optimal)
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    // code here
    int k=operators.size();
    vector<int> parents;
    for(int i=0;i<k;i++){
        parents.emplace_back(i);
    }
    vector<int> size_arr(k,1);
    vector<int> ans;
    vector<int> vec(n*m,-1);
    int up1,up2;
    int new_ans=0;
    vector<int> dx={0,-1,0,1,0};
    vector<int> dy={0,0,1,0,-1};
    int currentIndex,neighborIndex;
    for(int i=0;i<k;i++){
        new_ans++;
        currentIndex=m*operators[i][0]+operators[i][1];
        for(int j=0;j<5;j++){
            if(operators[i][0]+dx[j]>=0 && operators[i][0]+dx[j]<n && operators[i][1]+dy[j]>=0 && operators[i][1]+dy[j]<m){
                neighborIndex=m*(operators[i][0]+dx[j])+operators[i][1]+dy[j];
                if(vec[neighborIndex]!=-1){
                    up1=findUp(parents,size_arr,i);
                    up2=findUp(parents,size_arr,vec[neighborIndex]);
                    if(up1!=up2){
                        if(size_arr[up1]>=size_arr[up2]){
                            parents[up2]=up1;
                            size_arr[up1]+=size_arr[up2];
                        }
                        else{
                            parents[up1]=up2;
                            size_arr[up2]+=size_arr[up1];
                        }
                        new_ans--;   
                    }
                }
            }
        }
        vec[currentIndex]=i;
        ans.emplace_back(new_ans);
    }
    return ans;
}

//method2(more optimal)
// vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
//     // code here
//     int k=operators.size();
//     vector<int> parents;
//     for(int i=0;i<k;i++){
//         parents.emplace_back(i);
//     }
//     vector<int> size_arr(k,1);
//     vector<int> ans;
//     map<pair<int,int>,int> mpp;
//     map<pair<int,int>,int>::iterator temp1,temp2,temp3,temp4,temp5;
//     pair<int,int> p1,p2,p3,p4,p5;
//     int up1,up2;
//     int new_ans=0;
//     for(int i=0;i<k;i++){
//         p1=make_pair(operators[i][0]+1,operators[i][1]);
//         p2=make_pair(operators[i][0]-1,operators[i][1]);
//         p3=make_pair(operators[i][0],operators[i][1]+1);
//         p4=make_pair(operators[i][0],operators[i][1]-1);
//         p5=make_pair(operators[i][0],operators[i][1]);
//         temp1=mpp.find(p1);
//         temp2=mpp.find(p2);
//         temp3=mpp.find(p3);
//         temp4=mpp.find(p4);
//         temp5=mpp.find(p5);
//         new_ans++;
//         if(temp1!=mpp.end()){
//             up1=findUp(parents,size_arr,i);
//             up2=findUp(parents,size_arr,mpp[p1]);
//             if(up1!=up2){
//                 if(size_arr[up1]>=size_arr[up2]){
//                     parents[up2]=up1;
//                     size_arr[up1]+=size_arr[up2];
//                 }
//                 else{
//                     parents[up1]=up2;
//                     size_arr[up2]+=size_arr[up1];
//                 }
//                 new_ans--;   
//             }
//         }
//         if(temp2!=mpp.end()){
//             up1=findUp(parents,size_arr,i);
//             up2=findUp(parents,size_arr,mpp[p2]);
//             if(up1!=up2){
//                 if(size_arr[up1]>=size_arr[up2]){
//                     parents[up2]=up1;
//                     size_arr[up1]+=size_arr[up2];
//                 }
//                 else{
//                     parents[up1]=up2;
//                     size_arr[up2]+=size_arr[up1];
//                 }
//                 new_ans--;
//             }
//         }
//         if(temp3!=mpp.end()){
//             up1=findUp(parents,size_arr,i);
//             up2=findUp(parents,size_arr,mpp[p3]);
//             if(up1!=up2){
//                 if(size_arr[up1]>=size_arr[up2]){
//                     parents[up2]=up1;
//                     size_arr[up1]+=size_arr[up2];
//                 }
//                 else{
//                     parents[up1]=up2;
//                     size_arr[up2]+=size_arr[up1];
//                 }
//                 new_ans--;
//             }
//         }
//         if(temp4!=mpp.end()){
//             up1=findUp(parents,size_arr,i);
//             up2=findUp(parents,size_arr,mpp[p4]);
//             if(up1!=up2){
//                 if(size_arr[up1]>=size_arr[up2]){
//                     parents[up2]=up1;
//                     size_arr[up1]+=size_arr[up2];
//                 }
//                 else{
//                     parents[up1]=up2;
//                     size_arr[up2]+=size_arr[up1];
//                 }
//                 new_ans--;
//             }
//         }
//         if(temp5!=mpp.end()){
//             up1=findUp(parents,size_arr,i);
//             up2=findUp(parents,size_arr,mpp[p5]);
//             if(up1!=up2){
//                 if(size_arr[up1]>=size_arr[up2]){
//                     parents[up2]=up1;
//                     size_arr[up1]+=size_arr[up2];
//                 }
//                 else{
//                     parents[up1]=up2;
//                     size_arr[up2]+=size_arr[up1];
//                 }
//                 new_ans--;
//             }
//         }
//         mpp[p5]=i;
//         ans.emplace_back(new_ans);
//     }
//     return ans;
// }


//method1(unoptimal)
// vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
//     // code here
//     int k=operators.size();
//     vector<int> parents;
//     for(int i=0;i<k;i++){
//         parents.emplace_back(i);
//     }
//     vector<int> size_arr(k,1);
//     vector<int> ans;
//     for(int i=0;i<k;i++){
//         for(int j=0;j<i;j++){
//             if((operators[j][0]+1==operators[i][0] && operators[j][1]==operators[i][1])||
//             (operators[j][0]==operators[i][0] && operators[j][1]-1==operators[i][1])||
//             (operators[j][0]-1==operators[i][0] && operators[j][1]==operators[i][1])||
//             (operators[j][0]==operators[i][0] && operators[j][1]+1==operators[i][1])||
//             (operators[j][0]==operators[i][0] && operators[j][1]==operators[i][1])){
//                 int up1=findUp(parents,size_arr,i);
//                 int up2=findUp(parents,size_arr,j);
//                 if(up1==up2) continue;
//                 if(size_arr[up1]>=size_arr[up2]){
//                     parents[up2]=up1;
//                     size_arr[up1]+=size_arr[up2];
//                 }
//                 else{
//                     parents[up1]=up2;
//                     size_arr[up2]+=size_arr[up1];
//                 }
//             }
//         }
//         set<int> s;
//         for(int j=0;j<=i;j++){
//             s.insert(findUp(parents,size_arr,j));
//         }
//         ans.emplace_back(s.size());
//     }
//     return ans;
// }