#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
    priority_queue<int> greed_pq;
    priority_queue<int> cookies;
    int greed_size=0;
    for(int cookie:s){
        cookies.push(cookie);
    }
    for(int greed:g){
        greed_pq.push(greed);
        greed_size++;
    }
    int temp1,temp2;
    int ans=0;
    for(int i=0;i<greed_size;i++){
        temp1=INT32_MAX;
        temp2=cookies.top();
        cookies.pop();
        while((temp1>temp2)&&(!greed_pq.empty())){
            temp1=greed_pq.top();
            greed_pq.pop();
            if(temp1<=temp2){
                ans++;
                break;
            } 
        }
        if(cookies.empty()) return ans;
    }
    return ans;
}

int main(){
    vector<int> g,s;
    int n,m,temp;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>temp;
        g.emplace_back(temp);
    }
    for(int i=0;i<m;i++){
        cin>>temp;
        s.emplace_back(temp);
    }
    cout<<findContentChildren(g,s)<<endl;
    return 0;
}