#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids){
    int n=asteroids.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && asteroids[i]<0 && st.top()>=0 && st.top()<abs(asteroids[i])) st.pop();
        if(!st.empty() && asteroids[i]<0 && st.top()>=0 && st.top()==abs(asteroids[i])){
            st.pop();
            continue;
        }
        else if(!st.empty() && asteroids[i]<0 && st.top()>=0 && st.top()>abs(asteroids[i])) continue;
        else st.push(asteroids[i]);
    }
    vector<int> ans;
    while(!st.empty()){
        ans.emplace_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}