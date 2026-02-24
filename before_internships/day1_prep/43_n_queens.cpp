#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> queen_fill(pair<int,int> qPosition,map<pair<int,int>,int>& workspace,int n){
    set<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        map<pair<int,int>,int>::iterator it=workspace.find(make_pair(i,qPosition.second));
        if(it!=workspace.end()){
            ans.insert(make_pair(i,qPosition.second));
            workspace.erase(it);
        }
    }
    for(int j=0;j<n;j++){
        map<pair<int,int>,int>::iterator it=workspace.find(make_pair(qPosition.first,j));
        if(it!=workspace.end()){
            ans.insert(make_pair(qPosition.first,j));
            workspace.erase(it);
        }
    }
    for(int i=0;i<n;i++){
        pair<int,int> p=make_pair(qPosition.first-i,qPosition.second-i);
        if(p.first>=0 && p.first<n && p.second>=0 && p.second<n){
            map<pair<int,int>,int>::iterator it=workspace.find(p);
            if(it!=workspace.end()){
                ans.insert(p);
                workspace.erase(it);
            }
        }
        p=make_pair(qPosition.first+i,qPosition.second-i);
        if(p.first>=0 && p.first<n && p.second>=0 && p.second<n){
            map<pair<int,int>,int>::iterator it=workspace.find(p);
            if(it!=workspace.end()){
                ans.insert(p);
                workspace.erase(it);
            }
        }
        p=make_pair(qPosition.first-i,qPosition.second+i);
        if(p.first>=0 && p.first<n && p.second>=0 && p.second<n){
            map<pair<int,int>,int>::iterator it=workspace.find(p);
            if(it!=workspace.end()){
                ans.insert(p);
                workspace.erase(it);
            }
        }
        p=make_pair(qPosition.first+i,qPosition.second+i);
        if(p.first>=0 && p.first<n && p.second>=0 && p.second<n){
            map<pair<int,int>,int>::iterator it=workspace.find(p);
            if(it!=workspace.end()){
                ans.insert(p);
                workspace.erase(it);
            }
        }
    }
    return ans;
}

void f(int i,map<pair<int,int>,int>& workspace,int n,vector<string>& current,set<vector<string>>& ans){
    if(i==0){
        ans.insert(current);
        return;
    }
    if(workspace.size()==0) return;
    map<pair<int,int>,int> older_workspace=workspace;
    for(auto& p:older_workspace){
        if(p.first.first==i-1){
            set<pair<int,int>> s=queen_fill(p.first,workspace,n);
            current[p.first.first][p.first.second]='Q';
            f(i-1,workspace,n,current,ans);
            current[p.first.first][p.first.second]='.';
            for(const pair<int,int>& p:s) workspace[p]=1;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    set<vector<string>> ans;
    vector<string> current;
    string s(n,'.');
    for(int i=0;i<n;i++) current.emplace_back(s);
    map<pair<int,int>,int> workspace;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            workspace[make_pair(i,j)]=1;
        }
    }
    f(n,workspace,n,current,ans);
    vector<vector<string>> actual_ans(ans.begin(),ans.end());
    return actual_ans;
}