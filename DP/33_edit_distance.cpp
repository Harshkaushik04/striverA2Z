#include<bits/stdc++.h>
using namespace std;

int minimum(int x,int y,int z){
    if(x<=y){
        if(x<=z) return x;
        else return z;
    }
    else{
        if(y<=z) return y;
        else return z;
    }
    return x; //function wouldnt reach here
}

int minDistance(string word1, string word2) {
    int size1=word1.size(),size2=word2.size();
    if(size1==0) return size2;
    if(size2==0) return size1;
    vector<int> current(size2,0);
    vector<int> last(size2,0);
    //base case
    bool flag=false;
    int index=size2;
    for(int j=0;j<size2;j++){
        if(word2[j]==word1[0]){
            flag=true;
            index=j;
            break;
        }
    }
    if(flag){
        for(int j=index;j<size2;j++){
            last[j]=j;
        }
        for(int j=0;j<index;j++){
            last[j]=j+1;
        }
    }
    else{
        for(int j=0;j<size2;j++){
            last[j]=j+1;
        }
    }
    vector<int> tempList(size1,0);
    flag=false;
    for(int i=0;i<size1;i++){
        if(word1[i]==word2[0]){
            flag=true;
            index=i;
            break;
        }
    }
    if(flag){
        for(int i=index;i<size1;i++){
            tempList[i]=i;
        }
        for(int i=0;i<index;i++){
            tempList[i]=i+1;
        }
    }
    else{
        for(int i=0;i<size1;i++){
            tempList[i]=i+1;
        }
    }
    int temp1,temp2,temp3;
    for(int i=1;i<size1;i++){
        current[0]=tempList[i];
        for(int j=1;j<size2;j++){
            if(word1[i]==word2[j]) current[j]=last[j-1];
            else{
                temp1=last[j];
                temp2=current[j-1];
                temp3=last[j-1];
                current[j]=1+minimum(temp1,temp2,temp3);
            }
        }
        last=current;
    }
    return last[size2-1];
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<minDistance(s1,s2)<<endl;
    return 0;
}