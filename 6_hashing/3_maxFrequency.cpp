#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;


int maxFrequency(vector<int> nums, int k) {
    int maxElement=*max_element(nums.begin(),nums.end());
    int num_size=nums.size();
    vector<int> frequency(maxElement,0);
    vector<long long> value(maxElement,0);
    long long sum=0;
    bool flag=false;
    for(int i=0;i<num_size;i++){
        frequency[nums[i]-1]+=1;
    }
    for(int i=0;i<maxElement;i++){
        flag=false;
        if(frequency[i]!=0){
            sum=0;
            value[i]=frequency[i];
        for(int j=i;j>=0;j--){
            sum+=(long long)(i-j)*frequency[j];
            if(i!=j){
                value[i]+=frequency[j];
            }
            if(sum>k){
                sum-=(long long)(i-j)*frequency[j];
                value[i]-=frequency[j];
                for(int m=0;m<frequency[j];m++){
                    sum+=(i-j);
                    value[i]+=1;
                    if(sum==k){
                        flag=true;
                        // cout<<"hi1:"<<i+1<<endl;
                        break;
                    }
                    else if(sum>k){
                        sum-=(i-j);
                        value[i]-=1;
                        flag=true;
                        // cout<<"hi2:"<<i+1<<endl;
                        break;
                    }
                }
            }
            else if(sum==k){
                flag=true;
            }
            // if(i==9995){
            //     cout<<"sum:"<<sum<<endl;
            //     cout<<"value:"<<value[i]<<endl;
            // }
            if(flag){
                break;
            }
        }
        }
    }
    // int value_size=value.size();
    // for(int i=0;i<value_size;i++){
    //     if(i>=9898){
    //         cout<<i+1<<"->"<<value[i]<<endl;
    //     }
    // }
    return *max_element(value.begin(),value.end());
}

int main(){
    cout<<maxFrequency({9979,9938,9947,9916,9995,9981,9981,9931,9984,9942,9946,9946,9945,9931,9908,9920,9929,9917,9904,9945,9963,9910,9942,9965,9915,9981,9908,9919,9975,9904,9934,9922,9989,9946,9928,9928,9940,9941,9995,9905,9903,9980,9917,9940,9910,9994,9909,9965,9972,9931,9975,9913,9983,9943,9996,9917,9994,9991,9948,9961,9921,9981,9928,9933,9905,9957,9953,9940,9958,9982,9900,9912,9959,9992,9978,9988,9940,9985,9945,9900,9956,9976,9972,9914,9903,9978,9965,9987,9926,9963,9968,9962,9995,9963,9960,9986,9916,9911,9976,9988,9952,9914,9934,9929,9962,9999,9988,9901,9925,9983,9991,9915,9930,9949,9931,9944,9947,9921,9982,9984,9998,9945,9907,9900,9992,9945,9995,9941,9930,9918,9961,9960,9900,9952,9952,9954,9976,9970,9990,9947,9910,9908,9935,9971,9971,10000,9941,9983,9949,9985,9992,9996,9918,9930,9994,9970,9989,9975,9960,9973,9993,9900,9915,9974,9966,9978,9926,9937,9936,9952,9996,9996,9912,9915,9976,9976,9901,9926,9959,9989,9976,9904,9999,9925,9934,9947,9950,9985,9985,9932,9922,9962,9962,9993,9912,9924,9992,9941,9959,9954,9943,9995,9992,9928,9992,9920,9984,9917,9976,9971,9927,9917,9923,9948,9929,9990,9990,9921,9989,9910,9921},2636)<<endl;
    return 0;
}