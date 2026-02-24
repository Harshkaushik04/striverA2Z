#include<bits/stdc++.h>
using namespace std;

bool whether_eligible(int i,int j,vector<vector<int>>& bubbles,vector<pair<int,int>>& changes){
    int m=bubbles.size();
    int n=bubbles[0].size();
    int count=0;
    for(pair<int,int>& change:changes){
        pair<int,int> co=make_pair(i+change.first,j+change.second);
        if(co.first>=0 && co.first<m && co.second>=0 && co.second<n){
            if(bubbles[co.first][co.second]==bubbles[i][j]) count++;
        }
    }
    if(count>=2) return true;
    return false;
}

vector<vector<int>> bubble_explosion(vector<vector<int>>& bubbles){ //-1 is visited
    int m=bubbles.size();
    int n=bubbles[0].size();
    vector<pair<int,int>> changes={{-1,0},{0,1},{1,0},{0,-1}};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(bubbles[i][j]==-1) continue;
            if(!whether_eligible(i,j,bubbles,changes)) continue;
            queue<pair<int,pair<int,int>>> q;
            q.push(make_pair(bubbles[i][j],make_pair(i,j)));
            while(!q.empty()){
                int qSize=q.size();
                for(int k=0;k<qSize;k++){
                    pair<int,pair<int,int>> curr=q.front();
                    int color=curr.first;
                    q.pop();
                    for(pair<int,int>& change:changes){
                        pair<int,int> co=make_pair(i+change.first,j+change.second);
                        if(co.first>=0 && co.first<m && co.second>=0 && co.second<n){
                            if(bubbles[co.first][co.second]==color){ //unvisited
                                bubbles[co.first][co.second]=-1;
                                q.push(make_pair(color,make_pair(co.first,co.second)));
                            }
                        }
                    }
                }
            }
        }
    }

}