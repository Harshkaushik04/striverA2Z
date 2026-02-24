#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    string s;
    cin>>m>>n;
    vector<vector<char>> grid(m,vector<char>(n,'A')); //initialise
    for(int i=0;i<m;i++){
        cin>>s;
        for(int j=0;j<n;j++) grid[i][j]=s[j];
    }
    if(grid[0][0]!='A'){
        cout<<0<<endl;
        return 0;
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    vector<int> x_change={-1,-1,0,1,1,1,0,-1};
    vector<int> y_change={0,1,1,1,0,-1,-1,-1};
    char current_letter='A';
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            pair<int,int> current=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int x1=current.first+x_change[i];
                int y1=current.second+y_change[i];
                if(x1>=0 && x1<m && y1>=0 && y1<n && grid[x1][y1]==current_letter+1) q.push(make_pair(x1,y1));
            }
        }
        current_letter++;
    }
    cout<<"case 1: "<<current_letter-'A'<<endl;
    int temp,temp1;
    cin>>temp>>temp1;
    return 0;
}