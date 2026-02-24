#include<bits/stdc++.h>
using namespace std;

bool compare_strings(string& s1,string& s2){ //assuming s1.size() and s2.size() is same and assuming s1 and s2 are different
    int k=0;
    int n=s1.size();
    for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]) k++;
        if(k>1) return false;
    }
    return true;
}

void modifiedDfs(string& node,unordered_map<string,vector<string>>& adj,unordered_map<string,int>& path_visited,
            vector<vector<string>>& ans,int& distance,vector<string>& current,unordered_map<string,int>& distance_arr,
            string& endWord){
    if(path_visited[node]==-1){
        if(distance>distance_arr[endWord] || distance>distance_arr[node]) return;
        current.emplace_back(node);
        distance++;
        if(node==endWord && distance==distance_arr[endWord]){
            ans.emplace_back(current);
            current.pop_back();
            distance--;
            return;
        }
        path_visited[node]=1;
        for(string& neighbor:adj[node]){
            if(distance_arr[neighbor]==distance_arr[node]+1)
                modifiedDfs(neighbor,adj,path_visited,ans,distance,current,distance_arr,endWord);
        }
        distance--;
        path_visited[node]=-1;
        current.pop_back();
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
    unordered_map<string,vector<string>> adj;
    unordered_map<string,set<string>> temp;
    temp[beginWord]=set<string>{};
    int n=wordList.size();
    bool found=false;
    for(int i=0;i<n;i++){
        if(wordList[i]==endWord) found=true;
        if(beginWord==wordList[i]) continue;
        if(compare_strings(beginWord,wordList[i])){
            temp[beginWord].insert(wordList[i]);
            if(temp.find(wordList[i])==temp.end()) temp[wordList[i]]=set<string>{beginWord};
            else temp[wordList[i]].insert(beginWord);
        }
    }
    if(!found) return vector<vector<string>>{};
    if(beginWord==endWord) return vector<vector<string>>{vector<string>{beginWord}};
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(wordList[i]==wordList[j]) continue;
            if(compare_strings(wordList[i],wordList[j])){
                if(temp.find(wordList[i])==temp.end()) temp[wordList[i]]=set<string>{wordList[j]};
                else temp[wordList[i]].insert(wordList[j]);
                if(temp.find(wordList[j])==temp.end()) temp[wordList[j]]=set<string>{wordList[i]};
                else temp[wordList[j]].insert(wordList[i]);
            }
        }
    }
    for(auto& p:temp) adj[p.first]=vector<string>(p.second.begin(),p.second.end());
    queue<string> q;
    unordered_map<string,int> visited_arr;
    for(auto& p:adj) visited_arr[p.first]=-1;
    q.push(beginWord);
    visited_arr[beginWord]=1;
    int distance=0;
    bool flag=false;
    unordered_map<string,int> distance_arr;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            string current=q.front();
            q.pop();
            if(distance_arr.find(current)==distance_arr.end()) distance_arr[current]=distance;
            for(string& neighbor:adj[current]){
                if(visited_arr[neighbor]==-1){
                    visited_arr[neighbor]=1;
                    q.push(neighbor);
                }
            }
        }
        distance++;
    }
    vector<vector<string>> ans;
    vector<string> current;
    distance=-1;
    string start=beginWord;
    unordered_map<string,int> path_visited;
    for(auto& p:adj) path_visited[p.first]=-1;
    modifiedDfs(start,adj,path_visited,ans,distance,current,distance_arr,endWord);
    return ans;
}