#include<iostream>
#include<vector>
using namespace std;

int rowWithMax1s(vector<vector<int>> &arr) {
    int arrSize=arr.size(),arrSize2=arr[0].size();
    int low,mid,high;
    int mini=INT32_MAX,miniValue=-1;
    for(int i=0;i<arrSize;i++){
        low=0,high=arrSize2-1,mid=(low+high)/2;
        while(low<=high){
            if(arr[i][mid]==0){
                low=mid+1,mid=(low+high)/2;
            }
            else if(mid>0){
                if(arr[i][mid]==1){
                    if(arr[i][mid-1]==0){
                        if(mini>mid){
                            mini=mid,miniValue=i;
                        }
                        break;
                    }
                    else{
                        high=mid-1,mid=(low+high)/2;
                    }
                }
            }
            else if(mid==0){
                if(arr[i][mid]==1){
                    if(mini>mid){
                        mini=mid,miniValue=i;
                    }
                }
                break;
            }
        }
    }
    return miniValue;
}

int main(){
    vector<vector<int>> arr={{0,0,0,0,0,1,1,1,1},{0,0,0,0,0,0,1,1,1},{0,0,0,1,1,1,1,1,1},{0,0,0,0,1,1,1,1,1}};
    int ans=rowWithMax1s(arr);
    cout<<ans<<endl;
    return 0;
}