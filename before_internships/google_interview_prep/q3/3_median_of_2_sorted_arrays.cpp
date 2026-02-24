#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1=nums1.size();
    int size2=nums2.size();
    if(size1==0){
        if(size2%2==0) return ((double)nums2[size2/2]+nums2[(size2-1)/2])/2;
        else return nums2[size2/2];
    }
    else if(size2==0){
        if(size1%2==0) return ((double)nums1[size1/2]+nums1[(size1-1)/2])/2;
        else return nums1[size1/2];
    }
	int ans=-1;
	int low=0;
	int high=nums2.size();
	int mid=(low+high)/2;
	int lower1,lower2,higher1,higher2;
	while(low<=high){
		if((size1+size2)/2-mid-1>=size1){
			low=mid+1;
			mid=(low+high)/2;
			continue;
		}
        if(mid>(size1+size2)/2){
            high=mid-1;
            mid=(low+high)/2;
            continue;
        }
		//write conditions
		//lower1=nums2[mid-1]->need to check if mid-1>=0
		if(mid-1>=0) lower1=nums2[mid-1];
		else lower1=INT32_MIN;
		//lower2=nums1[(size1+size2)/2-mid-1]
		if((size1+size2)/2-mid-1>=0) lower2=nums1[(size1+size2)/2-mid-1];
		else lower2=INT32_MIN;
		//higher1=nums2[mid]
		if(mid<nums2.size()) higher1=nums2[mid];
		else higher1=INT32_MAX;
		//higher2=nums1[(size1+size2)/2-mid];
		if((size1+size2)/2-mid<nums1.size()) higher2=nums1[(size1+size2)/2-mid];
		else higher2=INT32_MAX;
		if(lower1<=higher2 && lower2<=higher1){
			if((size1+size2)%2==0) return ((double)max(lower1,lower2)+min(higher1,higher2))/2;	
			else return min(higher1,higher2);
			break;
		}
		else if(lower1>higher2){
			high=mid-1;
			mid=(low+high)/2;
		}
		else if(lower2>higher1){
			low=mid+1;
			mid=(low+high)/2;
		}
	}
    return -1;
}


int main(){
    vector<int> nums1,nums2;
    int n1,n2;
    cin>>n1>>n2;
    int temp;
    for(int i=0;i<n1;i++){
        cin>>temp;
        nums1.emplace_back(temp);
    } 
    for(int i=0;i<n2;i++){
        cin>>temp;
        nums2.emplace_back(temp);
    } 
    double ans=findMedianSortedArrays(nums1,nums2);
    cout<<ans<<endl;
    return 0;
}
