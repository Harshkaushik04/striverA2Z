#include<bits/stdc++.h>
using namespace std;

void changeDirectionRight(string& direction){
    if(direction=="north") direction="east";
    else if(direction=="east") direction="south";
    else if(direction=="south") direction="west";
    else direction="north";
}

void changeDirectionLeft(string& direction){
    if(direction=="north") direction="west";
    else if(direction=="east") direction="north";
    else if(direction=="south") direction="east";
    else direction="south";
}

void updateAns(int& ans,pair<int,int>& position){
    ans=max(ans,(int)pow(position.first,2)+(int)pow(position.second,2));
}

struct pair_hash {
    inline size_t operator()(const std::pair<int, int> & v) const {
        return std::hash<int>()(v.first) ^ (std::hash<int>()(v.second) << 1);
    }
};

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int n=commands.size();
    int m=obstacles.size();
    unordered_set<pair<int,int>,pair_hash> s;
    for(int i=0;i<m;i++){
        s.insert(pair<int,int>{obstacles[i][0],obstacles[i][1]});
    }        
    string direction="north";
    pair<int,int> position={0,0};
    int ans=0;
    for(int i=0;i<n;i++){
        if(commands[i]==-2) changeDirectionLeft(direction);
        else if(commands[i]==-1) changeDirectionRight(direction);
        else{
            int num_moves=commands[i];
            for(int j=0;j<num_moves;j++){
                if(direction=="north"){
                    if(s.find(pair<int,int>{position.first,position.second+1})==s.end()) position.second++;
                    else break;
                }
                else if(direction=="east"){
                    if(s.find(pair<int,int>{position.first+1,position.second})==s.end()) position.first++;
                    else break;
                }
                else if(direction=="south"){
                    if(s.find(pair<int,int>{position.first,position.second-1})==s.end()) position.second--;
                    else break;
                }
                else{
                    if(s.find(pair<int,int>{position.first-1,position.second})==s.end()) position.first--;
                    else break;
                }
                updateAns(ans,position);
            }
            updateAns(ans,position);
        }
    }
    return ans;
}