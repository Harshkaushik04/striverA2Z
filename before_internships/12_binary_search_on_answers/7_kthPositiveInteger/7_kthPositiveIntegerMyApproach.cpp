#include<iostream>
#include<vector>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int current=0,counter=0;
    int arrSize=arr.size();
    for(int i=0;i<arrSize;i++){
        current++;
        while(arr[i]!=current){
            cout<<"counter:"<<counter<<endl;
            cout<<"hi1:"<<arr[i]<<" "<<current<<endl;
            counter++,current++;
            if(counter==k){
                return current-1;
            }
        }
    }
    while(counter<k){
        counter++,current++;
        cout<<"hi2"<<endl;
        if(counter==k){
            return current;
        }
    }
    return current-1;
}

int main(){
    vector<int> arr={1,2,3,4};
    int ans=findKthPositive(arr,2);
    cout<<ans<<endl;
    return 0;
}