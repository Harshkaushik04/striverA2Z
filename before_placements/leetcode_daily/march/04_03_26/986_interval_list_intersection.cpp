#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    int n1=firstList.size();
    int n2=secondList.size();
    int i=0,j=0;
    vector<vector<int>> ans;
    while(i<n1 && j<n2){
        if(firstList[i][1]<secondList[j][0]) i++;
        else if(firstList[i][0]>secondList[j][1]) j++;
        else{
            if(firstList[i][1]>secondList[j][1]){
                if(firstList[i][0]>=secondList[j][0]) ans.emplace_back(vector<int>{firstList[i][0],secondList[j][1]});
                else ans.emplace_back(vector<int>{secondList[j][0],secondList[j][1]});
                j++;
            }
            else if(firstList[i][1]<secondList[j][1]){
                if(secondList[j][0]>=firstList[i][0]) ans.emplace_back(vector<int>{secondList[j][0],firstList[i][1]});
                else ans.emplace_back(vector<int>{firstList[i][0],firstList[i][1]});
                i++;
            }
            else{
                if(firstList[i][0]>=secondList[j][0]) ans.emplace_back(vector<int>{firstList[i][0],firstList[i][1]});
                else ans.emplace_back(vector<int>{secondList[j][0],secondList[j][1]});
                i++;
                j++;
            }
        }
    }
    return ans;
}