#include<bits/stdc++.h>
using namespace std;
void solve(int index,int n,vector<vector<char>>& board,bool& flag){
	if(flag) return;
	int num_row=index/n;
	int num_col=index%n;
	if(index>=pow(n,2)){
		flag=true;
return; 
}
	if(board[num_row][num_col]!='.'){
        solve(index+1,n,board,flag);
        return;
    }
	unordered_map<char,int> options;
	int row_box_lower_limit=num_row/3;
	int col_box_lower_limit=num_col/3;
	for(int row=row_box_lower_limit*3;row<3*(row_box_lower_limit+1);row++){
		for(int col=col_box_lower_limit*3;col<3*(col_box_lower_limit+1);col++){
			if(board[row][col]=='.') continue;
			if(options.find(board[row][col])==options.end()) options[board[row][col]]=1;
		}
	}
	for(int it=0;it<n;it++){
		if(board[it][num_col]!='.' && options.find(board[it][num_col])==options.end()) options[board[it][num_col]]=1; 
        if(board[num_row][it]!='.' && options.find(board[num_row][it])==options.end()) options[board[num_row][it]]=1; 
}
vector<char> actual_options;
for(int i=1;i<=9;i++){
	if(options.find(i+'0')==options.end()) actual_options.emplace_back(i+'0');
}
if(actual_options.size()==0) return;
for(int option:actual_options){
	board[num_row][num_col]=option;
	solve(index+1,n,board,flag);
	if(flag) return;
	board[num_row][num_col]='.';
}
}

void solveSudoku(vector<vector<char>>& board){
	int n=board.size();
	bool flag=false;
	solve(0,n,board,flag);
}
