#include<iostream>
#include<vector>

using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    int aIndex=0,bIndex=0;
    int aSize=a.size();
    int bSize=b.size();
    vector<int> unionArr;
    if(a[0]>b[0]){
        unionArr.emplace_back(b[0]);
        bIndex++;
    }
    else if(a[0]<b[0]){
        unionArr.emplace_back(a[0]);
        aIndex++;
    }
    else{
        unionArr.emplace_back(a[0]);
        aIndex++;
        bIndex++;
    }
    while(aIndex<aSize && bIndex<bSize){
        if(a[aIndex]>b[bIndex]){
            if(b[bIndex]!=unionArr[unionArr.size()-1]){
                unionArr.emplace_back(b[bIndex]);
                bIndex++;
            }
            else{
                bIndex++;
            }
        }
        else if(a[aIndex]<b[bIndex]){
            if(a[aIndex]!=unionArr[unionArr.size()-1]){
                unionArr.emplace_back(a[aIndex]);
                aIndex++;
            }
            else{
                aIndex++;
            }
        }
        else{
            if(a[aIndex]!=unionArr[unionArr.size()-1]){
                unionArr.emplace_back(a[aIndex]);
                aIndex++;
                bIndex++;
            }
            else{
                aIndex++;
                bIndex++;
            }
        }
    }
    while(aIndex<aSize){
        if(a[aIndex]!=unionArr[unionArr.size()-1]){
            unionArr.emplace_back(a[aIndex]);
            aIndex++;
        }
        else{
            aIndex++;
        }
    }
    while(bIndex<bSize){
        if(b[bIndex]!=unionArr[unionArr.size()-1]){
            unionArr.emplace_back(b[bIndex]);
            bIndex++;
        }
        else{
            bIndex++;
        }
    }
    return unionArr;
}