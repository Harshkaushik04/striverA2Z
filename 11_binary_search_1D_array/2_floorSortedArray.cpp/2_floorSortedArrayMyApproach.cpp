#include<iostream>
#include<vector>

using namespace std;

int findFloor(vector<int>& arr, int k) {
    int low=0,high=arr.size()-1,mid=(low+high)/2;
    while(true){
        // cout<<low<<" "<<mid<<" "<<high<<endl;
        if(low==high){
            if(k>=arr[low]){
                return low;
            }
            else{
                return low-1;
            }
        }
        else if(low>high){
            if(low==0){
                return -1;
            }
            else{
                return low-1;
            }
        }
        if(k==arr[mid]){
            return mid;
        }
        else if(k>arr[mid]){
            low=mid+1;
            mid=(low+high)/2;
        }
        else{
            high=mid-1;
            mid=(low+high)/2;
        }
    }
}

int main(){
    vector<int> test={185, 2899, 4531, 5626, 6513, 11461, 11870, 12381, 12433, 13278, 13906, 14926, 15733, 17306, 17570, 17821, 18216, 18665, 19050, 20068, 24282, 24641, 24687, 24847, 25586, 27821, 28786, 31518, 31921};
    int target=17655;
    int result=findFloor(test,target);
    cout<<result<<endl;
    return 0;
}

