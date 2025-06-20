#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    map<int,int> mpp;
    mpp[5]=0,mpp[10]=0,mpp[20]=0;
    for(int bill:bills){
        if(bill==5) mpp[5]++;
        else if(bill==10){
            if(mpp[5]==0) return false;
            else{
                mpp[5]--;
                mpp[10]++;
            }
        }
        else{
            if(mpp[5]==0) return false;
            else if(mpp[10]==0){
                if(mpp[5]<3) return false;
                else{
                    mpp[5]-=3;
                    mpp[20]++;
                }
            }
            else{
                mpp[5]--;
                mpp[10]--;
                mpp[20]++;
            }
        }
    }
    return true;
}