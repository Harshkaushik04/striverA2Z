#include<iostream>
#include<vector>

using namespace std;

int findFloor(vector<int>& arr, int k) {
    int low=0,high=arr.size()-1,mid=(low+high)/2;
    int ans=arr.size();
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]<k){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(ans==arr.size()){
        return -1;
    }
    else if(arr[ans]<=k){
        return ans;
    }
    else{
        return -1;
    }
}

int main(){
    vector<int> test={185, 2899, 4531, 5626, 6513, 11461, 11870, 12381, 12433, 13278, 13906, 14926, 15733, 17306, 17570, 17821, 18216, 18665, 19050, 20068, 24282, 24641, 24687, 24847, 25586, 27821, 28786, 31518, 31921};
    int target=17655;
    int result=findFloor(test,target);
    cout<<result<<endl;
    return 0;
}

