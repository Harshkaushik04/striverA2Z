#include<bits/stdc++.h>
using namespace std;

/*
satisifiability of inequalities
x>y y>x

Q) You are given a set of M strict inequalities (<, >) only between certain variables and you have to output if the set of inequalities are satisfiable or not.
Eg) [(x>y), (y>z), (x>z)]àreturn T­rue.
Eg) [(x>y), (y>x)]àreturn False.
Constraints: M=1e5.

x>y =>  x<---y
y>x =>  y<---x
*/

bool whether_possible(vector<string> expressions){
    int m=expressions.size();
    unordered_map<char,vector<char>> adj;
    for(string& expression:expressions){
        if(expression[1]=='>'){
            if(adj.find(expression[2])==adj.end()) adj[expression[2]]=vector<char>{expression[0]};
            else adj[expression[2]].emplace_back(expression[0]);
            if(adj.find(expression[0])==adj.end()) adj[expression[0]]=vector<char>{};
        }
        else{
            if(adj.find(expression[0])==adj.end()) adj[expression[0]]=vector<char>{expression[2]};
            else adj[expression[0]].emplace_back(expression[2]);
            if(adj.find(expression[2])==adj.end()) adj[expression[2]]=vector<char>{};
        }
    }
    //indegree arr char--->int
    unordered_map<char,int> indegree;
    for(pair<const char,vector<char>>& out_edges:adj){
        indegree[out_edges.first]=0;
    }
    queue<char> q;
    for(pair<const char,vector<char>>& p:adj){
        for(char ch:p.second) indegree[ch]++;
    }
    for(pair<const char,int>& node:indegree){
        if(indegree[node.first]==0) q.push(node.first);
    }
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            char current=q.front();
            q.pop();
            for(char neighbor:adj[current]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0) q.push(neighbor);
            }
        }
    }
    for(pair<const char,int>& node:indegree){
        if(node.second!=0) return false;
    }
    return true;
}


int main(){
    int n;
    cin>>n;
    vector<string> expressions(n);
    for(int i=0;i<n;i++) cin>>expressions[i];
    cout<<whether_possible(expressions)<<endl;
    return 0;
}
