#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.size()!=goal.size()) return false;
    list<char> dll;
    list<char> goal_dll;
    int n=s.size();
    for(int i=0;i<n;i++){
        dll.push_back(s[i]);
        goal_dll.push_back(goal[i]);
    }
    for(int i=0;i<n;i++){
        if(dll==goal_dll) return true;
        char ch=dll.front();
        dll.pop_front();
        dll.push_back(ch);
    }
    return false;
}