#include<bits/stdc++.h>
using namespace std;
//incorrect for now
//this is just kahn algo question varient
string findOrder(vector<string> &words) {
    unordered_map<char,vector<char>> adj;
    int wordsSize=words.size();
    int length=0;
    for(int i=0;i<wordsSize-1;i++){
        string s1=words[i],s2=words[i+1];
        int s1Size=s1.size(),s2Size=s2.size();
        int j=0;
        while(j<s1Size && j<s2Size){
            if(s1[j]!=s2[j]){
                if(adj.find(s1[j])!=adj.end()){
                    adj[s1[j]].emplace_back(s2[j]);
                }
                else{
                    adj[s1[j]]={s2[j]};
                    length++;
                }
                break;
            }
            j++;
        }
    }
    //main procedure(topo sort:kahn algo)
    queue<char> q;
    unordered_map<char,int> indegree;
    for(pair<char,vector<char>> p:adj){
        for(char ch:p.second){
            if(indegree.find(ch)!=indegree.end()){
                indegree[ch]++;
            }
            else{
                indegree[ch]=1;
            }
        }
        if(indegree.find(p.first)==indegree.end()){
            indegree[p.first]=0;
        }
    }
    for(pair<char,int> p:indegree){
        if(p.second==0){
            q.push(p.first);
        }
    }
    while(!q.empty()){
        char current=q.front();
        q.pop();
        for(char neighbor:adj[current]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0) {
                q.push(neighbor);
            }
        }
    }
    for(pair<char,int> p:indegree){
        if(p.second!=0) return "false";
    }
    return "true";
}