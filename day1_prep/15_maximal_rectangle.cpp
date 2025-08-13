#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int n=heights.size();
    vector<int> pse(n,-1);
    vector<int> nse(n,n);
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
        if(!st.empty()) pse[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
        if(!st.empty()) nse[i]=st.top();
        st.push(i);
    }
    int maxi=-1;
    for(int i=0;i<n;i++){
        maxi=max(maxi,(nse[i]-pse[i]-1)*heights[i]);
    }
    return maxi;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> heights(m,0);
    int maxi=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]!='0') heights[j]++;
            else heights[j]=0;
        }
        maxi=max(maxi,largestRectangleArea(heights));
    }
    return maxi;
}
