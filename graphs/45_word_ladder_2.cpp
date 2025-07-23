#include<bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList,vector<vector<int>>& adj,int& final_index
,vector<int>& distance_arr) {
    int n=wordList.size();
    bool check=false;
    for(int i=0;i<n;i++){
        if(wordList[i]==endWord){
            check=true;
            final_index=i;
            break;
        }
    }
    if(!check) return 0;
    // 1 to n:for wordList, 0 for beginWord
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
            distance_arr[current]=length;
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

void modified_dfs(int i,int dest,vector<string>& wordList,vector<vector<int>>& adj,int len,
    set<vector<string>>& all_paths,vector<string>& current_path,vector<int>& visited_arr,int& current_distance
    ,string beginWord,vector<int>& distance_arr){
        if(visited_arr[i]==-1){
            visited_arr[i]=1;
            current_distance++;
            if(i!=0) current_path.emplace_back(wordList[i-1]);
            else current_path.emplace_back(beginWord);
            if(i==dest && current_distance==len) all_paths.insert(current_path);
            for(int neighbor:adj[i]){
                cout<<i<<endl;
                if(distance_arr[i]+1==distance_arr[neighbor]) modified_dfs(neighbor,dest,wordList,adj,len,all_paths,current_path,visited_arr,current_distance,beginWord,distance_arr);
            }
            current_path.pop_back();
            current_distance--;
            visited_arr[i]=-1;
        }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    int n=wordList.size();
    vector<vector<int>> adj(n+1,vector<int>());
    int final_index=-1;
    int INF=1e9;
    vector<int> distance_arr(n+1,INF);
    int len=ladderLength(beginWord,endWord,wordList,adj,final_index,distance_arr);
    vector<string> current_path;
    set<vector<string>> all_paths;
    vector<int> visited_arr(n+1,-1);
    int current_distance=0;
    modified_dfs(0,final_index+1,wordList,adj,len,all_paths,current_path,visited_arr,current_distance,beginWord,distance_arr);
    vector<vector<string>> vec(all_paths.begin(),all_paths.end());
    return vec;
}

int main(){
    string s1,s2,temp;
    vector<string> s;
    int n;
    cin>>s1;
    cin>>s2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        s.emplace_back(temp);
    }
    vector<vector<string>> all_paths=findLadders(s1,s2,s);
    int m=all_paths.size();
    int n1=all_paths[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n1;j++){
            cout<<all_paths[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}