#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int>& arr){
    for(int i:arr) cout<<i<<" ";
    cout<<endl<<"=================="<<endl;
}

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

int main(){
    int n;
    cin>>n;
    vector<int> heights(n,-1);
    for(int i=0;i<n;i++) cin>>heights[i];
    cout<<largestRectangleArea(heights)<<endl;
    return 0;
}