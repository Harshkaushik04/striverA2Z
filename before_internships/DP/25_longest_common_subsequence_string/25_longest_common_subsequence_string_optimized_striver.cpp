#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int size1=text1.size();
    int size2=text2.size();
    int temp;
    vector<int> current(size2+1,0);
    vector<int> last(size2+1,0);
    //base case is that at any size=0,=0
    for(int i=1;i<=size1;i++){
        for(int j=1;j<=size2;j++){
            if(text1[i-1]==text2[j-1]) current[j]=1+last[j-1];
            else current[j]=max(current[j],last[j-1]);
        }
        last=current;
    }
    return last[size2];
}
