#include<bits/stdc++.h>
using namespace std;

/*
can make adjacency list in form of unordered_map<char,vector<char>>
*/

void print_unordered_map(unordered_map<char,vector<char>>& um){
    for(auto& p:um){
        cout<<p.first<<":";
        for(char ch:p.second) cout<<ch<<" ";
        cout<<endl;
    }
    cout<<"==========================="<<endl;
}

void compare_strings(string& s1,string& s2,unordered_map<char,vector<char>>& adj,
    unordered_map<char,int>& indegree_arr,bool& flag){
    if(s1.size()==0 || s2.size()==0) return;
    int i=0;
    int m=s1.size(),n=s2.size();
    int ssize=min(m,n);
    while(i<ssize){
        if(s1[i]==s2[i]) i++;
        else{
            adj[s1[i]].emplace_back(s2[i]);
            indegree_arr[s2[i]]++;
            return;
        }
    }
    if(i>=n && m!=n) flag=true;
}

string findOrder(vector<string> &words) {
    // code here
    unordered_map<char,vector<char>> adj;
    int n=words.size();
    set<char> set_nodes_list;
    for(string& s:words){
        for(char ch:s) set_nodes_list.insert(ch);
    }
    vector<char> nodes_list(set_nodes_list.begin(),set_nodes_list.end());
    if(n==1){
        string ans;
        for(char ch:nodes_list) ans+=ch;
        return ans;
    }
    unordered_map<char,int> indegree_arr;
    for(char node:nodes_list) indegree_arr[node]=0;
    bool another_flag=false;
    for(int i=0;i<n-1;i++){
        compare_strings(words[i],words[i+1],adj,indegree_arr,another_flag);
        if(another_flag) return "";
    }
    // print_unordered_map(adj);
    bool flag=false;
    queue<char> q;
    string ans;
    for(auto& p:indegree_arr){
        if(p.second==0){
            q.push(p.first);
            ans+=p.first;
        }
    }
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            char current=q.front();
            q.pop();
            for(char neighbor:adj[current]){
                indegree_arr[neighbor]--;
                if(indegree_arr[neighbor]==0){
                    q.push(neighbor);
                    ans+=neighbor;
                }
            }
        }
    }
    for(auto& p:indegree_arr){
        if(p.second!=0) return "";
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++) cin>>words[i];
    string ans=findOrder(words);
    cout<<ans<<endl;
    return 0;
}