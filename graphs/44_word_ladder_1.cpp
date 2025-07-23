#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int n=wordList.size();
    bool check=false;
    int final_index=-1;
    for(int i=0;i<n;i++){
        if(wordList[i]==endWord){
            check=true;
            final_index=i;
            break;
        }
    }
    if(!check) return 0;
    // 1 to n:for wordList, 0 for beginWord
    vector<vector<int>> adj(n+1,vector<int>());
    int m=beginWord.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp=0;
            if(i!=j){
                for(int k=0;k<m;k++){
                    if(temp>1) break;
                    if(wordList[i][k]!=wordList[j][k]) temp++; 
                }
                if(temp==1){
                    adj[i+1].emplace_back(j+1);
                    adj[j+1].emplace_back(i+1);
                }
            }
        }
    } 
    for(int i=0;i<n;i++){
        int temp=0;
        for(int k=0;k<m;k++){
            if(beginWord[k]!=wordList[i][k]) temp++;
        }
        if(temp==1){
            adj[0].emplace_back(i+1);
            adj[i+1].emplace_back(0);
        }
    }
    queue<int> q;
    q.push(0);
    int length=0;
    vector<int> visited_arr(n+1,-1);
    bool flag=true;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            int current=q.front();
            q.pop();
            if(current==final_index+1){
                flag=false;
                break;
            }
            for(int neighbor:adj[current]){
                if(visited_arr[neighbor]==-1){
                    visited_arr[neighbor]=1;
                    q.push(neighbor);
                }
            }
        }
        length++;
        if(!flag) break;
    }
    if(!flag) return length;
    return 0;
}