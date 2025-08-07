//wrong

// #include<bits/stdc++.h>
// using namespace std;

// int largestIsland(vector<vector<int>>& grid){
// 	int n=grid.size();
// 	vector<vector<int>> visited_arr(n,vector<int>(n,-1));
// 	unordered_map<int,int> size_arr; //index to size
// 	vector<vector<int>> grid_to_index(n,vector<int>(n,-1));
// 	queue<pair<int,int>> q;
// 	vector<pair<int,int>> changes={make_pair(0,-1),make_pair(-1,0),make_pair(0,1),make_pair(1,0)};
//     int index=0;
//     int maxi=-1;
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			if(visited_arr[i][j]==-1 && grid[i][j]==1){
// 				index++;
// 				q.push(make_pair(i,j));
// 				grid_to_index[i][j]=index;
//                 visited_arr[i][j]=1;
//                 int nodes_size=0;
//                 while(!q.empty()){
//                     int qSize=q.size();
//                     for(int k=0;k<qSize;k++){
//                         pair<int,int> current=q.front();
//                         nodes_size++;
//                         q.pop();
//                         for(pair<int,int> change:changes){
//                             pair<int,int> neighbor=make_pair(change.first+current.first,change.second+current.second);
//                             if(neighbor.first>=0 && neighbor.first<n && neighbor.second>=0 && neighbor.second<n){
//                                 if(visited_arr[neighbor.first][neighbor.second]==-1){
//                                     q.push(neighbor);	
//                                     visited_arr[neighbor.first][neighbor.second]=1;
//                                     grid_to_index[neighbor.first][neighbor.second]=index;
//                                 }
//                             }
//                         }
//                     }
//                 }
//                 size_arr[index]=nodes_size;
//                 maxi=max(maxi,nodes_size);
//             }
//         }
//     }
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			if(grid[i][j]==0){
//                 unordered_map<int,int> indexes;
//                 int temp=1;
// 				for(pair<int,int> change:changes){
//                     pair<int,int> neighbor=make_pair(i+change.first,j+change.second);
//                     if(neighbor.first>=0 && neighbor.first<n && neighbor.second>=0 && neighbor.second<n &&
//                     grid[neighbor.first][neighbor.second]==1){
//                         if(indexes.find(grid_to_index[neighbor.first][neighbor.second])==indexes.end()){
//                             indexes[grid_to_index[neighbor.first][neighbor.second]]=1;
//                             temp+=size_arr[grid_to_index[neighbor.first][neighbor.second]];
//                         }
//                     }
//                 }
//                 maxi=max(maxi,temp);
// 			}
// 		}
// 	}
//     return maxi;
// }
