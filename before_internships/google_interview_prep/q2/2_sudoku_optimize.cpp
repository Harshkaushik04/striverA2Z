#include<bits/stdc++.h>
using namespace std;

void solve(int index,int n,vector<vector<char>>& board,bool& flag,vector<unordered_map<char,int>>& boxes,vector<unordered_map<char,int>>& rows,vector<unordered_map<char,int>>& cols){
	if(flag) return;
	int num_row=index/n;
	int num_col=index%n;
	if(index>=n*n){
		flag=true;
return; 
}
	if(board[num_row][num_col]!='.'){
        		solve(index+1,n,board,flag,boxes,rows,cols);
       		 return;
    	}
	//need to identify the box index
	int box_index=3*(num_row/3)+num_col/3;
	for(int option=1;option<=9;option++){
		char char_option=option+'0';
		if(boxes[box_index].find(char_option)==boxes[box_index].end()) continue;
		if(rows[num_row].find(char_option)==rows[num_row].end()) continue;
		if(cols[num_col].find(char_option)==cols[num_col].end()) continue;
		boxes[box_index].erase(char_option);
		rows[num_row].erase(char_option);
		cols[num_col].erase(char_option);
		board[num_row][num_col]=char_option;
		solve(index+1,n,board,flag,boxes,rows,cols);
		if(flag) return;
		boxes[box_index][char_option]=1;
		rows[num_row][char_option]=1;
		cols[num_col][char_option]=1;
	}
}

void solveSudoku(vector<vector<char>>& board){
	int n=board.size();
	bool flag=false;
	//making boxes,rows and cols: the collection of possibilities
	vector<unordered_map<char,int>> boxes,rows,cols;
	unordered_map<char,int> box_temp;
	unordered_map<char,int> row_temp;
	unordered_map<char,int> col_temp;
	for(int option=0;option<9;option++){
		row_temp[option]=1;
		box_temp[option]=1;
		col_temp[option]=1;
	}
	for(int i=0;i<9;i++){
		boxes.emplace_back(box_temp);
		rows.emplace_back(row_temp);
		cols.emplace_back(col_temp);
	}
	for(int row=0;row<9;row++){
		for(int col=0;col<9;col++){
			int box_index=3*(row/3)+col/3;
			if(board[row][col]!='.'){
				boxes[box_index].erase(board[row][col]);
				rows[row].erase(board[row][col]);
				cols[col].erase(board[row][col]);
			}
		}
	}
	solve(0,n,board,flag,boxes,rows,cols);
}

