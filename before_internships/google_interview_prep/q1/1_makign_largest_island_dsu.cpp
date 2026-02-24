//wrong:bfs doesnt work

// #include<bits/stdc++.h>
// using namespace std;

// //rank_arr isnt rank array but size array
// bool checkPair(pair<int,int>& node,int n){ //checks whether co ordinate is inside bounds
// 	if(node.first>=0 && node.first<n && node.second>=0 && node.second<n) return true;
// 	return false;
// }

// pair<int,int> findUp(vector<vector<pair<int,int>>>& parents,pair<int,int> node){ //finds ultimate parent
// 	if(parents[node.first][node.second]==node) return node;
// 	pair<int,int> up=findUp(parents,parents[node.first][node.second]);
// 	parents[node.first][node.second]=up;
// 	return up;
// }

// int searchNeighbors(pair<int,int>& node,int n,vector<vector<pair<int,int>>>& parents,vector<vector<int>>& rank_arr,vector<vector<int>>& grid){
// 	vector<pair<int,int>> changes={make_pair(-1,0),make_pair(0,1),make_pair(1,0),make_pair(0,-1)};
// 	int sum=0;
// 	map<pair<int,int>,int> mpp;
// 	for(pair<int,int>& change:changes){
// 		pair<int,int> neighbor=make_pair(node.first+change.first,node.second+change.second);
//         if(checkPair(neighbor,n) && grid[neighbor.first][neighbor.second]==1){
//             pair<int,int> up=findUp(parents,neighbor);
//             if(mpp.find(up)==mpp.end()){   
//                 sum+=rank_arr[up.first][up.second];
//                 mpp[up]=1;		
//             }
//         }
//     }
//     return sum;
// }

// void disjoint_set_union(pair<int,int>& node1,pair<int,int>& node2,vector<vector<pair<int,int>>>& parents,vector<vector<int>>& rank_arr){
// 	pair<int,int> up1=findUp(parents,node1);
// 	pair<int,int> up2=findUp(parents,node2);
// 	if(up1==up2) return;
// 	if(rank_arr[up1.first][up1.second]>rank_arr[up2.first][up2.second]){
// 		parents[up2.first][up2.second]=up1;
// 		rank_arr[up1.first][up1.second]+=rank_arr[up2.first][up2.second];
// 	}
// 	else{
//         parents[up1.first][up1.second]=up2;
//         rank_arr[up2.first][up2.second]+=rank_arr[up1.first][up1.second];
//     }
// }

// int largestIsland(vector<vector<int>>& grid){
// 	int n=grid.size();
// 	pair<int,int> p=make_pair(-1,-1);
// 	vector<vector<int>> visited_arr(n,vector<int>(n,-1));
// 	vector<vector<pair<int,int>>> parents(n,vector<pair<int,int>>(n,p));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             parents[i][j]=make_pair(i,j);
//         }
//     }
// 	vector<vector<int>> rank_arr(n,vector<int>(n,1));
// 	queue<pair<int,int>> q;
// 	vector<pair<int,int>> changes={make_pair(-1,0),make_pair(0,1),make_pair(1,0),make_pair(0,-1)};
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			if(visited_arr[i][j]==-1 && grid[i][j]==1){
// 				q.push(make_pair(i,j));
// 				visited_arr[i][j]=1;
// 				while(!q.empty()){
// 					int qSize=q.size();
// 					for(int i=0;i<qSize;i++){
// 						pair<int,int> current=q.front();
// 						q.pop();
// 						for(pair<int,int> change:changes){
// 							pair<int,int> neighbor=make_pair(current.first+change.first,current.second+change.second);
// if(checkPair(neighbor,n) && visited_arr[neighbor.first][neighbor.second]==-1){
// 	visited_arr[neighbor.first][neighbor.second]=1;
//     	disjoint_set_union(current,neighbor,parents,rank_arr);
// 	q.push(neighbor);
// 	}
// }
// 					}
// 				}
// 			}
// 		}
// 	}
//     int maxi=-1;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             maxi=max(maxi,rank_arr[i][j]);
//         }
//     }
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			if(grid[i][j]==0){
//                 pair<int,int> p=make_pair(i,j);
// 				int temp=searchNeighbors(p,n,parents,rank_arr,grid);
// 				maxi=max(maxi,temp+1);
// 			}
// 		}
// 	}
// 	return maxi;
// }
	
	
